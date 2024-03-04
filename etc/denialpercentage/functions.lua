function append_converted_timestamp(tag, timestamp, record)

    local datetime = record["HOST_DATE_TIME"]
    local year, month, day, hours, minutes, seconds = datetime:match('^(%d%d%d%d)(%d%d)(%d%d)(%d%d)(%d%d)(%d%d)$')
    if not year then
        -- Our entire match failed, and no captures were made
        error('could not parse date "' .. datetime .. '"')
    end
    local newDatetime = string.format('%s-%s-%s %s:%s:%s',year, month, day, hours, minutes, seconds)

    local new_record = record
    new_record["HOST_DATE_TIME"] = newDatetime
    new_record["SEQ_NO"]=record["GUID_1"] .. record["GUID_2"]
    return 2, timestamp, new_record
end

function lookup_processor(tag, timestamp, record)
    local processor_map={
        A = "first entry,1",
        B = "second entry,2",
        C = "third entry,3",
        D = "fourth entry,4",
        E = "fifth entry,5"
    }
    local new_record = record
    --print(record["GUID_1"],record["PROCESSOR"])
    local entry,number = processor_map[record["PROCESSOR"]]:match("(.+),(.+)")
    new_record["LOOKUP_VALUE_ENTRY"] = entry
    new_record["LOOKUP_VALUE_NUMBER"] = number
    new_record["CURR_TIMESTAMP"] = os.date("%Y %m %d",timestamp)
    new_record["EST_TIMESTAMP"] = os.time()
    return 1, new_record["EST_TIMESTAMP"], new_record
end

function denials_processor(tag, timestamp,record)

    local new_record = record
    if record["RECORD_TYPE"] == 3 then
        new_record["DENIAL_COUNT"]=1
    else
        new_record["DENIAL_COUNT"]=0
    end
    new_record["TOTAL_COUNT"]=1  
    return 1, timestamp, new_record
end

function percentage_processor(tag, timestamp, record)
    new_record = {}
    --new_record["RECORD_TIME"]=record["RECORD_TIME()"]
    new_record["WINDOW_STARTTIME"]=os.date("%Y-%m-%dT%H:%M:%S%Z", record["RECORD_TIME()"])
    --new_record["WINDOW_ENDTIME"]=os.date("%Y-%m-%dT%H:%M:%S%Z", os.time(now)))
    new_record["TXN_DATETIME"]=record["TRANSACTION_DATETIME"]
    new_record["COMPANY_DIVISION"]=record["COMPANY_DIVISION"]
    new_record["TOTAL_TXNS"]=record["total_txns"]
    new_record["DENIAL_TXNS"]=record["denial_txns"]
    new_record["DENIAL_PERCENTAGE"]=(record["denial_txns"]/record["total_txns"])*100
    return 1, timestamp,new_record
end

function set_record_time(tag, timestamp, record)
    local transaction_datetime = record["TRANSACTION_DATETIME"]
    local year, month, day, hours, minutes, seconds = transaction_datetime:match('^(%d%d%d%d)(%d%d)(%d%d)(%d%d)(%d%d)(%d%d)$')
    if not year then
        -- Our entire match failed, and no captures were made
        error('could not parse date "' .. datetime .. '"')
    end
    local new_timestamp = os.time({day=day,month=month,year=year,hour=hours,min=minutes,sec=seconds})


    local utc_seconds_shift = (function()
        local ts = os.time()
        local utc_date = os.date('!*t', ts)
        local utc_time = os.time(utc_date)
        local local_date = os.date('*t', ts)
        local local_time = os.time(local_date)
        return local_time - utc_time
      end)()

    --print(utc_seconds_shift)
    --print(new_timestamp)
    -- Manual hack for converting EST to UTC
    local new_timestamp=new_timestamp+18000


    -- WINDOWS START AND END TIME CALC
    --s1 = os.time()
    --x1 = os.date('*t',s1)
    --x1.day = x1.day - 200
    --x1.isdst = nil -- this prevents DST time changes
    --s2 = os.time(x1)
    --print(s1, os.date("%c", s1))
    --print(s2, os.date("%c", s2))
    print("")
    local window_timestamp = os.date('*t',new_timestamp)
    print("CURR_UTC_TIME=",os.date("%c",os.time(window_timestamp)))
    --print(window_timestamp.min)
    window_timestamp.min = window_timestamp.min - (window_timestamp.min%5)
    window_timestamp.sec = 0
    --print(window_timestamp.min)
    window_timestamp.isdst = nil
    local window_starttime = os.time(window_timestamp)
    print("WINDOW_STARTTIME=",os.date("%c",window_starttime))
    window_timestamp.min = window_timestamp.min + 5
    local window_endtime = os.time(window_timestamp)
    print("WINDOW_ENDTIME=",os.date("%c",window_endtime)) 

    return 1, new_timestamp, record
end

function cb_parse_ts(tag, timestamp, record)
    time=record["time"]
     if (time == nil) then
      return -1, 0, 0 -- drop entry instead of throwing error
    end
    pattern="(%d+)-(%d+)-(%d+) (%d+):(%d+):(%d+),(%d+)" -- example: 2020-01-14 17:23:58,634
    year,month,day,hour,minute,second,millisecond=time:match(pattern)
    new_timestamp = os.time({day=day,month=month,year=year,hour=hour,min=minute,sec=second}) + millisecond/1000
    return 1, new_timestamp, record
end


local function round5min(var)
    local h, m, ampm = var:match"^(%d+):(%d+)(%a+)$"
    local t = (({am=0,pm=12})[ampm:lower()]+h%12)*60+m+2
    t = t-t%5
    m = t%60
    t = (t-m)/60
    h = t%12
    return ("%d:%02d%s"):format((h-1)%12+1, m, ({"am","pm"})[(t-h)/12%2+1])
 end

local function round5min(var)
    local h, m, ampm = var:match"^(%d+):(%d+)(%a+)$"
    local t = (({am=0,pm=12})[ampm:lower()]+h%12)*60+m+2
    t = t-t%5
    m = t%60
    t = (t-m)/60
    h = t%12
    return ("%d:%02d%s"):format((h-1)%12+1, m, ({"am","pm"})[(t-h)/12%2+1])
 end