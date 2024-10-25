#!/bin/bash

# 定义文件名和优化级别
FILE="$1.c"
OPTIMIZATION_LEVELS=("O0" "O1" "O2" "Ofast")

# 数据规模
./data $2 9

# 创建一个CSV文件来存储结果
OUTPUT_FILE="$1$2_results.csv"
echo "优化级别,运行时间(s),内存占用(KB)" > $OUTPUT_FILE

# 遍历每个优化级别
for OPT_LEVEL in "${OPTIMIZATION_LEVELS[@]}"; do
    # 编译文件
    gcc -$OPT_LEVEL -o new_$OPT_LEVEL $FILE

    # 运行并统计时间和内存使用
    echo "Running with optimization level -$OPT_LEVEL..."
    TIME_OUTPUT=$(/usr/bin/time -f "%e,%M" ./new_$OPT_LEVEL 2>&1)

    # 解析时间和内存使用
    RUN_TIME=$(echo $TIME_OUTPUT | cut -d',' -f1)
    MEM_USAGE=$(echo $TIME_OUTPUT | cut -d',' -f2)

    # 将结果写入CSV文件
    echo "-$OPT_LEVEL,$RUN_TIME,$MEM_USAGE" >> $OUTPUT_FILE

    # 删除生成的可执行文件
    rm new_$OPT_LEVEL
done

echo "Results have been saved to $OUTPUT_FILE"
