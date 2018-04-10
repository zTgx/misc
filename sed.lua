#换行符替换为空格
sed ":a;N;s/\n/ /g;ta" a.txt

#or
sed ":a;N;s/\n/ /g;$!ba" a.txt

#or
sed ":a;$!N;s/\n/ /g;ba" a.txt
