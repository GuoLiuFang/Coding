//
//  main.cpp
//  Trainning
//
//  Created by LiuFangGuo on 5/28/17.
//  Copyright © 2017 LiuFangGuo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int * a = m > 0 ? &nums1[0] : NULL;
        int * b = n > 0 ? &nums2[0] : NULL;
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getKth(a, m, b, n, l) + getKth(a, m, b, n, r)) / 2.0;
    }
    int getKth(int s[], int m,int l[], int n, int k){
        if (m > n) {
            //从左到右，大的放后面
            return getKth(l, n, s, m, k);
        }
        if (m == 0) {
            //如果小的长度为空
            return l[k - 1];
        }
        if (k == 1) {
            //如果长度都不为空，而且要取第一个的话，那就比较下第一个谁更小就好。。
            return min(s[k - 1],l[k - 1]);
        }
        //二分查找法，确定边界。。
        int i = min(m,k / 2),j = k - i;
        if (s[i - 1] < l[j - 1]) {
            return getKth(s + i, m - i, l, j, k - i);
        } else {
            return getKth(s, i, l + j, n - j, k - j);
        }
    }
        int getPos(vector<int>& data, int key){
    //找到返回 index 下标，找不到返回插入位置。。
        int first = 0;
        int last = data.size() - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (key > data[mid]) {
                first = mid + 1;
            }else if (key < data[mid]){
                last = mid - 1;
            }else{
                return mid;
            }
        }
        return  first;
    }
        //实在无法忍受这个方法太经典了。。。变化点就在于 int mid = (first + last) / 2;
    
};


int main(int argc, const char * argv[]) {
    cout << "测试中xx文\n";
    std::cout << "Hello, World!\n";
    Solution s;
    vector<int> a = {};
    vector<int> b = {4,4,5};
        cout << s.findMedianSortedArrays(a,b)<< endl;
    
    return 0;
}

