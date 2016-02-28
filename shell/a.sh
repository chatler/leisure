#!/bin/sh

echo "using while:"
#while可以读取数个变量，第一个变量代表第一个字符串(由IFS变量决定分割符)，
#第二个代表变量代表第二个，依次类推，但是最后一个变量则代表剩下的所有，
#那么这里 $a 这是第一个字符串，$b 则是剩下的所有字符串，然后再对 $b 中
#的含有 $a 的进行全部替换为空。
while read a b
	do
		echo "$a ${b// $a}"
	done < testfile


echo "using awk:"
#其实所有的原理都是替换，awk呢利用 gsub() 进行全局替换，这点注意双引号
#内的问号，这是一个正则，在双引号中使用正则，学名叫 Dynamic Regexps.
awk '{a=$1;gsub(" ?"a,"");print a""$0}' testfile

echo "using sed:"
#这个也是一样的，利用 t label 来完成替换。
sed ':a;s/^\(.\)\(.*\) \1/\1\2/;ta' testfile

