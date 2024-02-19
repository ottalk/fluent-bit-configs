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
    new_record["RECORD_TIME"]=record["RECORD_TIME()"]
    new_record["TXN_DATETIME"]=record["TRANSACTION_DATETIME"]
    new_record["COMPANY_DIVISION"]=record["COMPANY_DIVISION"]
    new_record["TOTAL_TXNS"]=record["total_txns"]
    new_record["DENIAL_TXNS"]=record["denial_txns"]
    new_record["DENIAL_PERCENTAGE"]=(record["denial_txns"]/record["total_txns"])*100
    return 1, timestamp,new_record
end