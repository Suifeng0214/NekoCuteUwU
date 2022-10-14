# needed
ac.cpp
wa.cpp
gen.py
run.sh
# run.sh
set -e # 可以偵測程式 RE 時會停下來
g++ ac.cpp -o ac -std=c++14
g++ wa.cpp -o wa -std=c++14
for ((i=0;;i++))
do
    echo "$i"
    python3 gen.py > input
    ./ac < input > ac.out
    ./wa < input > wa.out
    diff ac.out wa.out || break
done

# cheatsheet
from random import * 
n = randint(1, 100) # [1,100]
ch = chr(randint(ord('a'), ord('z'))) 
# 從集合 s 選出 4 個不同的元素
choiceSet = sample(s, 4) 
# 從整數 1~n 選出 4 個不同的元素
choiceSet = sample(range(1, n+1), 4) 
# 把序列 arr 順序打亂 (產生1~n的一組permutation)
shuffle(arr) 

# 產生隨機一棵樹
# 每次從比自己小的節點選一個當連接自己的邊
for i in range(2, n+1):
    print(i, randint(1, i-1))