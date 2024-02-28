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
    local kc = io.popen("date --utc +%F'T'%H:%M:%S.%3N'Z'")
    new_record["FluentbitTime"] = kc:read('*a')
    kc:close()
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