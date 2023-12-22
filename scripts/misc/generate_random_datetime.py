#!/usr/bin/python3

import random
from datetime import datetime,timedelta

# Generate random datetime within last hour
end=datetime.now()
start=end + timedelta(minutes=-60)
random_date=end + (start - end) * random.random()
print(random_date)

# Generate random number of fixed length
print(random.randrange(111111,999999,6))