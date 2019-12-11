

--  C++中int、string等常见类型转换  https://www.cnblogs.com/gaobw/p/7070622.html 

-- CString与double互相转化  https://blog.csdn.net/sikong00/article/details/53726702/ 

CString str;
double num=1.46;

//str="1.46"
str.Format(_T("%lf"),num);

//str="1.5"(.1表示小数点后留1位，小数点后超过1位则四舍五入)
str.Format(_T("%.1lf"),num);

//str="1.4600"
str.Format(_T("%.4f"),num);

//str=" 1.4600"(前面有1个空格)
str.Format(_T("%7.4f"),num);

-- CString转int   https://www.cnblogs.com/hailexuexi/archive/2011/11/21/2257777.html 


CString strtemp = "100";  
  
int  intResult;  
  
intResult= atoi(strtemp);  
  
  
  
   
  水平井长度  6000 - 12000 
压裂段数 
射孔簇数 11 
入地液量
压裂液数据
  
  
  
  
-- C++ STL中Map的按Key排序和按Value排序  https://blog.csdn.net/iicy266/article/details/11906189   


// win32_c_001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 


#include<map>  
#include<string>  
#include<iostream>  
using namespace std;  

typedef pair<string, int> PAIR;  

ostream& operator<<(ostream& out, const PAIR& p) {  
	return out << p.first << "\t" << p.second;  
}  

int main() {  
	map<string, int> name_score_map;  
	name_score_map["10"] = 90;   
	name_score_map["11"] = 79;   
	name_score_map["12"] = 92;   
	name_score_map.insert(make_pair("13",99));  
	name_score_map.insert(make_pair("14",86)); 
	name_score_map["15"] = 92; 
	name_score_map["16"] = 92; 
	name_score_map["17"] = 92; 
	name_score_map["18"] = 92; 
	name_score_map["19"] = 92; 
	name_score_map["20"] = 9223; 
	name_score_map["21"] = 92; 
	name_score_map["22"] = 92; 
	name_score_map["23"] = 923; 
	name_score_map["555"] = 923; 
	name_score_map["556"] = 923; 
	name_score_map["24"] = 942; 
	name_score_map["25"] = 962; 
	name_score_map["26"] = 952; 
	for (map<string, int>::iterator iter = name_score_map.begin();  
		iter != name_score_map.end();  
		++iter) {  
			cout << *iter << endl;  
	}  
	getchar();
	return 0;  
} 


--C++ STL中Map的按Key排序和按Value排序  https://blog.csdn.net/acidgl8757/article/details/17416439 



#include<map>  
#include<string>  
#include<iostream>  
using namespace std;  

typedef pair<string, int> PAIR;  

ostream& operator<<(ostream& out, const PAIR& p) {  
	return out << p.first << "\t" << p.second;  
}  

int main() {  
	map<string, int> name_score_map;  
	name_score_map["LiMin"] = 90;   
	name_score_map["ZiLinMi"] = 79;   
	name_score_map["BoB"] = 92;   
	name_score_map.insert(make_pair("Bing",99));  
	name_score_map.insert(make_pair("Albert",86));  
	for (map<string, int>::iterator iter = name_score_map.begin();  
		iter != name_score_map.end();  
		++iter) {  
			cout << *iter << endl;  
	}  
	system("pause");
	return 0;  
}  

--   https://blog.csdn.net/ancientmoondjay/article/details/69361035 

#include<map>  
#include<string>  
#include<iostream>  
using namespace std;  

typedef pair<string, int> PAIR;  

ostream& operator<<(ostream& out, const PAIR& p) {  
	return out << p.first << "\t" << p.second;  
}  

int main() {  
	map<string, int, greater<string> > name_score_map;  
	name_score_map["LiMin"] = 90;   
	name_score_map["ZiLinMi"] = 79;   
	name_score_map["BoB"] = 92;   
	name_score_map.insert(make_pair("Bing",99));  
	name_score_map.insert(make_pair("Albert",86));  
	for (map<string, int>::iterator iter = name_score_map.begin();  
		iter != name_score_map.end();  
		++iter) {  
			cout << *iter << endl;  
	}  
	system("pause");
	return 0;  
}  





-- std::vector 的几种遍历方式比较   https://blog.csdn.net/ls306196689/article/details/35787955 



 方式一

for (size_t i =0; i < vec.size(); i ++) {

        int d = vec[i];

        }


 方式二

size_t len = vec.size();

    for (size_t i =0; i < len; i ++) {

        int d = vec[i];

    }

方式三
for (auto it = vec.begin(); it != vec.end(); it ++) {

        int d = *it;

    }

方式四
for (int i:vec) {

        int d = i;

    }



方式五

    for_each(vec.begin(), vec.end(), [](int i){

        int d = i;

    });
	
	
vector 清空 	 https://blog.csdn.net/u012580994/article/details/43932701 

vector <int> vecInt;
    for (int i=0;i<500;i++)
    {
        vecInt.push_back(i);
    }
    int j= vecInt.capacity();   //j=512
    i = vecInt.size();          //i=500       
	
第一种办法使用 clear ，清空元素，但不回收空间
    vecInt.clear();
	
第三种办法 最简单的使用swap,清除元素并回收内存
    vector <int>().swap(vecInt);  //清除容器并最小化它的容量，
//   vecInt.swap(vector<int>()) ;     另一种写法
    j= vecInt.capacity();       //j=0  
    i = vecInt.size();          //i=0 
	
	

--   二维vector遍历 https://blog.csdn.net/fendou123kaixin/article/details/51259873 




--  map删除元素的三种方式 https://blog.csdn.net/zvall/article/details/52267007 


删除键为bfff指向的元素  
  
cmap.erase("bfff");  
  
  
删除迭代器 key所指向的元素  
map<string,int>::iterator key = cmap.find("mykey");  
  if(key!=cmap.end())  
 {  
    cmap.erase(key);  
 }  
  
删除所有元素  
cmap.erase(cmap.begin(),cmap.end());  




--  去重，  https://www.cnblogs.com/lianshuiwuyi/p/8177601.html


  vector<int> nums;
unique(nums.begin(), nums.end()); 


-- 为什么使用了unique还有重复的元素呢？  https://zhidao.baidu.com/question/369099262037612364.html   


std::unique 使用之前要先排序。
sort( myVector.begin(), myVector.end() );





--  Vector中去除重复元素  https://www.cnblogs.com/pengjieliu/p/6624638.html 



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v;
    cout << "Number of vector's element : " << endl;
    int number;
    cin >> number;
    for (int i = 0; i < number; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}





-- list、vector和deque的区别  https://blog.csdn.net/gogokongyin/article/details/51178378 


--    两个 vector 怎么合并？ https://blog.csdn.net/cau_eric/article/details/26011627 

insert方式：(以下为将vec1和vec2的内容合并到vec3中)
vector<string>vec1,vec2,vec3;
//... vec1,vec2赋值
vec3.insert(vec3.end(),vec1.begin(),vec1.end());
vec3.insert(vec3.end(),vec2.begin(),vec2.end()); 



merge方式：
vector<string>vec1,vec2,vec3;
//... vec1,vec2赋值
sort(vec1.begin(),vec1.end());
sort(vec2.begin(),vec2.end());
vec3.resize(vec1.size()+vec2.size());
merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),vec3.begin());



 -- C++标准库---transform()   http://lib.csdn.net/article/cplusplus/32641 



 --  find ，find_first_of ， find_if ， adjacent_find 的使用  https://www.cnblogs.com/heyonggang/p/3241789.html 

 

--    在vector中通过下标删除元素  https://blog.csdn.net/wusecaiyun/article/details/46815355 

删除单个元素，你应该这样做：

std::vector<int> vec;

vec.push_back(6);
vec.push_back(-17);
vec.push_back(12);

// 删除第二个元素 (vec[1])
vec.erase(vec.begin() + 1);
或者要一次性删除多个元素，你应该这样做：

// 删除第二个和第三个元素 (vec[1], vec[2])
vec.erase(vec.begin() + 1, vec.begin() + 3); 
 
  

 
 
 Gas wells 气井
 
 
 
 
 
  












	
	