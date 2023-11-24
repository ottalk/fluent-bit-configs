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