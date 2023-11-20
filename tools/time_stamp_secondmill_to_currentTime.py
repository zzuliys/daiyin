from datetime import datetime, timezone, timedelta

def convert_timestamp_to_beijing_time(timestamp_ms):
    # 将13位毫秒级时间戳转化为秒
    timestamp_sec = timestamp_ms / 1000.0

    # 创建一个包含UTC时间的datetime对象
    utc_datetime = datetime.utcfromtimestamp(timestamp_sec).replace(tzinfo=timezone.utc)

    # 获取北京时区的UTC偏移
    beijing_offset = timezone(timedelta(hours=8))

    # 使用时区信息进行转换，得到北京时间
    beijing_time = utc_datetime.astimezone(beijing_offset)

    # 格式化输出，包含毫秒
    formatted_time = beijing_time.strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
    
    return formatted_time

timestamp_ms = 1700209837911
beijing_time = convert_timestamp_to_beijing_time(timestamp_ms)
print("北京时间:", beijing_time)
