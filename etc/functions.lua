function append_converted_timestamp(tag, timestamp, record)

    local datetime = record["HOST_DATE_TIME"]
    local year, month, day, hours, minutes, seconds = datetime:match('^(%d%d%d%d)(%d%d)(%d%d)(%d%d)(%d%d)(%d%d)$')
    if not year then
        -- Our entire match failed, and no captures were made
        error('could not parse date "' .. datetime .. '"')
    end
    local newDatetime = string.format('%s-%s-%s %s:%s:%s',year, month, day, hours, minutes, seconds)

    new_record = record
    new_record["HOST_DATE_TIME"] = newDatetime
    new_record["SEQ_NO"]=record["GUID_1"] .. record["GUID_2"]
    return 2, timestamp, new_record
end

function lookup_processor(tag, timestamp, record)
    processor_map={
        AAABBC = "first entry,1",
        AABCCC = "second entry,2",
        CCCAAAA = "third entry,3",
        DDDEEEE = "fourth entry,4",
        ABBBBCCC = "fifth entry,5"
    }
    new_record = record
    entry,number = processor_map[record["PROCESSOR"]]:match("(.+),(.+)")
    new_record["LOOKUP_VALUE_ENTRY"] = entry
    new_record["LOOKUP_VALUE_NUMBER"] = number
    return 2, timestamp, new_record
end