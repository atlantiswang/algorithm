## 平衡二叉查找树
二叉查找树可以降低搜索时的时间复杂度，但前提是平衡二叉树  
二叉树平衡的方法有：
* 红黑树
* AVL
* Treap
* SBT

基础方法是二叉树的旋转，包括：  
LL\RR\LR\RL 四种旋转方法。

## 红黑树

红黑树是其中的一种平衡方法。通过三条规则来实现平衡，但由于  
这三条规则死记不容易理解而易忘。所以我总结为以下好记的几句话：  

    树的两头都是黑的，中间路径上可有黑有红，但红的不能连续出现，
    而黑的可以连续出现。每条路径中黑的个数是相同的。

注意红黑树会在最后加一个黑的节点。  
每次增加节点着红色优先，增加后，看路径中黑的个数是否超过了其它路径中的。如果
超过了就要做旋转，旋转以后看是不是还满足条件，如果不满足要重新着色。

整个过程没有判断是否平衡，只在判断条件是否满足。条件满足时，其实也就是平衡了

## 排序算法 
* 稳定性：如果相同的元素在排序后前后顺序不变就是稳定的，反之就是不稳定排序 
* 冒泡、快速、插入、选择。。。