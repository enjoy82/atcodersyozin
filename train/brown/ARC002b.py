import datetime

dt = datetime.timedelta(days=1)

k = input().split("/")
a = int(k[0])
b = int(k[1])
c = int(k[2])
mid = datetime.date(a, b, c)
while 1:
    year = mid.year
    month = mid.month
    day = mid.day
    if year % (month * day) == 0:
        month = str(month)
        if(len(month) == 1):
            month = "0" + month
        day = str(day)
        if(len(day) == 1):
            day = "0" + day
        print(str(year) + "/" + str(month) + "/" + str(day))
        exit()
    else:
        mid = mid + dt