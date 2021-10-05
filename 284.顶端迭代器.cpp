/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */
//注意，是继承了STL中的Iterator类
//https://blog.csdn.net/CSDN_564174144/article/details/76231626
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		auto tmp=*this;
        return tmp.next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return Iterator::next();
	}
	
	bool hasNext() const {
	    return Iterator::hasNext();
	}
};
// @lc code=end

