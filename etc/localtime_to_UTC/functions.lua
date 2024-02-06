function M.makeTimeStamp(dateString)  
    local pattern = "(%d+)%-(%d+)%-(%d+)T(%d+):(%d+):(%d+)([%+%-])(%d+)%:(%d+)"  
    local xyear, xmonth, xday, xhour, xminute,   
    xseconds, xoffset, xoffsethour, xoffsetmin = dateString:match(pattern)  
    local convertedTimestamp = os.time({year = xyear, month = xmonth,   
    day = xday, hour = xhour, min = xminute, sec = xseconds})  
    local offset = xoffsethour \* 60 + xoffsetmin  
    if xoffset == "-" then offset = offset \* -1 end  
    return convertedTimestamp + offset  
   end  


function cb_fix_timestamp(tag, timestamp, record)

    --TRANSACTION_DATETIME = 20240205134732
    local datetime = record["TRANSACTION_DATETIME"]
    local year, month, day, hours, minutes, seconds = datetime:match('^(%d%d%d%d)(%d%d)(%d%d)(%d%d)(%d%d)(%d%d)$')
    if not year then
        -- Our entire match failed, and no captures were made
        error('could not parse date "' .. datetime .. '"')
    end
    local newDatetime = string.format('%s-%s-%s %s:%s:%s',year, month, day, hours, minutes, seconds)

    new_record=record
    local ts = os.time();
    local utcdate   = os.date("!*t", ts)
    print("utcdate",utcdate)
    local localdate = os.date("*t", ts)
    print("localdate",localdate)
    local estdate = os.date('!%Y-%m-%d-%H:%M:%S%Z', ts)
    print("estdate",estdate)
    --localdate.isdst = false -- this is the trick
    utc_time_diff = os.difftime(os.time(estdate), os.time(utcdate))
    print ("utc_time_diff: ",utc_time_diff)

    new_record["TRANSACTION_DATETIME"]=new_record["TRANSACTION_DATETIME"] - utc_time_diff
    return 2, timestamp, new_record
end