## `string: find(a,pos)`

find(str,pos) 函数可以用来查找字符串中一个字符 / 字符串在 pos（含）之后第一次出现的位置（若不传参给 pos 则默认为 0）。如果没有出现，则返回 string::npos（被定义为 -1，但类型仍为 size_t/unsigned long）。