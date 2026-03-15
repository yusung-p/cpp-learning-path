#include <iostream>
#include <vector>//用vector删除有序数组中的重复项
using namespace std;
int removeDuplicates(vector<int>& nums){
    if (nums.empty()){
        return 0;
    }
    int index=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[index]){
            index++;
            nums[index]=nums[i];
        }
    }
    return index+1;
}
int main(){
    vector<int>nums={1,1,2,2,3,4,4,5};
    int len=removeDuplicates(nums);
    cout<<"长度为："<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}