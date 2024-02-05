function cb_fix_timestamp(tag, timestamp, record)
    new_record=record
    local utcdate   = os.date("!*t", ts)
    local localdate = os.date("*t", ts)
    localdate.isdst = false -- this is the trick
    utc_time_diff = os.difftime(os.time(localdate), os.time(utcdate))
    utc_time_diff = os.difftime(os.time(localdate), os.time(utcdate))
    print ("utc_time_diff: ",utc_time_diff)
    new_record["TRANSACTION_DATETIME"]=new_record["TRANSACTION_DATETIME"] - utc_time_diff
    return 2, timestamp, new_record
end