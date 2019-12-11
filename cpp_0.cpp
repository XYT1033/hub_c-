


-- vs2008断点失效  https://www.cnblogs.com/fangyukuan/archive/2010/12/20/1911730.html

Tools->Option->debugging->General  找到 Require source files to exactly match the original version   要求源文件与原始版本完全匹配 不要打勾 






 https://www.cnblogs.com/hailexuexi/archive/2011/11/21/2257777.html 
 
 
 -- lib文件  https://blog.csdn.net/rznice/article/details/51657593 
 
 
 
  

 
 
 
 -- https://blog.csdn.net/lsfreeing/article/details/73064808 
 
 
 
 
  错误	1	fatal error LNK1104: 无法打开文件“f:\work\slgem\tools\graphdll\graphdllheader.h.dir/../../../lib/debug/GraphDlld.lib”	DataInputSystem
 
 
 
 错误	44	fatal error C1859: “Debug\GraphDllD.pch”意外的预编译头错误， 只需重新运行编译器就可能修复此问题	f:\work\slgem\tools\graphdll\tidestone\f1findreplaceinfo.cpp	7
 
 
 
 
 
 错误	1	error PRJ0019: 某个工具从以下位置返回了错误代码: "正在执行生成后事件..."	SLRMDatabase
 
 
 
 

-- OnOK()与OnCancel()  https://blog.csdn.net/u012372584/article/details/53432634 

 
--   https://www.cnblogs.com/yuehui/archive/2012/06/18/2553210.html 
 
 
 #pragma warning(disable : 4786 )    

#include <string>   

#include <iostream>   

#include <algorithm>   

#include <map>   

#include <vector>   

using namespace std;   

typedef map<string, string> STRING2STRING;   

typedef std::map<string, vector<string > > STRING2VECTOR;   

 

int main()   

{   

    std::map<string, string > map_test;   

    map_test.insert(STRING2STRING::value_type("2001", "test1"));   

    map_test.insert(STRING2STRING::value_type("2002", "test2"));   

    map_test.insert(STRING2STRING::value_type("2003", "test3"));   

    map_test.insert(STRING2STRING::value_type("2004", "test4"));   

    map_test.insert(STRING2STRING::value_type("2005", "test5"));   

 

    map<string, string>::const_iterator map_conitor = map_test.begin();   

    for(; map_conitor!= map_test.end(); map_conitor++)   

    {   

        cout<<map_conitor->first<<"  "<<map_conitor->second<<endl;      

    }   

    cout<<"////////////////////////////////////////////////////////n";   

    std::vector<string> vec1;   

    vec1.push_back("test1_vector1");   

    vec1.push_back("test1_vector2");   

    vec1.push_back("test1_vector3");   

    vec1.push_back("test1_vector4");   

    std::vector<string> vec2;   

    vec2.push_back("test2_vector1");   

    vec2.push_back("test2_vector2");   

    vec2.push_back("test2_vector3");   

    vec2.push_back("test2_vector4");   

 

    std::map<string , vector<string> > testMap;   

    testMap.insert(STRING2VECTOR::value_type("10001",vec1));   

    testMap.insert(STRING2VECTOR::value_type("10002",vec2));   

    std::map<string, vector<string> >::iterator map_it = testMap.begin();   

    for ( ; map_it != testMap.end(); map_it++)   

    {   

        cout<<map_it->first<<"/t";   

        vector<string>::iterator mapvec_itor = map_it->second.begin();   

        for ( ; mapvec_itor !=  map_it->second.end(); mapvec_itor++)   

        {   

            cout<<(*mapvec_itor)<<" ";   

        }   

        cout<<endl;   

    }   

    cout<<"/n///////////////////////////////////////////////////////"<<endl;   

 

    map<string,vector<string> >::iterator iter=testMap.find( "10002" );   

    if(iter!=testMap.end()) //should like this   

    {   

        vector<string>::iterator it = iter->second.begin();   

        while(it != iter->second.end())   

        {   

            cout<<(*it++)<<endl;   

        }   

    }   

    return 0;   

}  


-- 

#pragma warning(disable : 4786 ) 

#include <string>

#include <iostream>

#include <algorithm>

#include <map>

#include <vector>

using namespace std;

typedef map<string, string> STRING2STRING;

typedef std::map<string, vector<string > > STRING2VECTOR;

 

int main()

{

    std::map<string, string > map_test;

    map_test.insert(STRING2STRING::value_type("2001", "test1"));

    map_test.insert(STRING2STRING::value_type("2002", "test2"));

    map_test.insert(STRING2STRING::value_type("2003", "test3"));

    map_test.insert(STRING2STRING::value_type("2004", "test4"));

    map_test.insert(STRING2STRING::value_type("2005", "test5"));

 

    map<string, string>::const_iterator map_conitor = map_test.begin();

    for(; map_conitor!= map_test.end(); map_conitor++)

    {

        cout<<map_conitor->first<<"  "<<map_conitor->second<<endl;   

    }

    cout<<"////////////////////////////////////////////////////////n";

    std::vector<string> vec1;

    vec1.push_back("test1_vector1");

    vec1.push_back("test1_vector2");

    vec1.push_back("test1_vector3");

    vec1.push_back("test1_vector4");

    std::vector<string> vec2;

    vec2.push_back("test2_vector1");

    vec2.push_back("test2_vector2");

    vec2.push_back("test2_vector3");

    vec2.push_back("test2_vector4");

 

    std::map<string , vector<string> > testMap;

    testMap.insert(STRING2VECTOR::value_type("10001",vec1));

    testMap.insert(STRING2VECTOR::value_type("10002",vec2));

    std::map<string, vector<string> >::iterator map_it = testMap.begin();

    for ( ; map_it != testMap.end(); map_it++)

    {

        cout<<map_it->first<<"/t";

        vector<string>::iterator mapvec_itor = map_it->second.begin();

        for ( ; mapvec_itor !=  map_it->second.end(); mapvec_itor++)

        {

            cout<<(*mapvec_itor)<<" ";

        }

        cout<<endl;

    }

    cout<<"/n///////////////////////////////////////////////////////"<<endl;

 

    map<string,vector<string> >::iterator iter=testMap.find( "10002" );

    if(iter!=testMap.end()) //should like this

    {

        vector<string>::iterator it = iter->second.begin();

        while(it != iter->second.end())

        {

            cout<<(*it++)<<endl;

        }

    }

    return 0;

} 





--  iterator 和 const_iterator  https://www.cnblogs.com/saintlas/p/5840190.html 


 
-- max_element	  https://www.cnblogs.com/ECJTUACM-873284962/p/6734225.html 


-- C# 求链表 list 中 属性的 最大值 最小值   https://www.cnblogs.com/yilinyangyu/p/8042961.html 

/// <summary>
    /// 用于测试属性的类
    /// </summary>
    public class ListTest
    {
        private int a;
        public int A
        {
            get { return a; }
            set { a = value; }
        }
    }


class Program
    {
        static void Main(string[] args)
        {
            List<ListTest> lst = new List<ListTest>();
            //初始化列表数据，分别给属性A复制1，2，10
            ListTest lstTest = new ListTest() { A = 1 };
            lst.Add(lstTest);
            lstTest = new ListTest() { A = 2 };
            lst.Add(lstTest);
            lstTest = new ListTest() { A = 10 };
            lst.Add(lstTest);

            int maxA = lst.Max(x => x.A);//获取链表中对象属性A的最大值，maxA的值为10，若要求最小值同理用Min方法
            Console.Write("链表lstTest中属性A的最大值是：" + maxA);
            Console.Read();
        }
    }






-- c++如何编译release https://blog.csdn.net/avatar1912/article/details/7897073

 



--   f:\work\Slgem\Tools\GVcTools\cpp\SLDzyUtility.cpp 

void CSLDzyUtility::DecodeStrLine(CString StrLine, CStringArray &ColValues,CString m_Fgf)
//分解行字符串为分列数据
//StrLine为行字符串,ColValues为分列结果
//m_Fgf分隔符
{
	ColValues.RemoveAll();
	if(m_Fgf.IsEmpty()) return;//未设置分隔符号

	//前后分隔符号的删除
	TCHAR Fgf = m_Fgf.GetAt(0);
	StrLine.TrimLeft(Fgf);
	StrLine.TrimRight(Fgf);
	if(StrLine.IsEmpty()) return;

	BOOL flag = true;//处于非分隔区
	int p1=0;
	int len = StrLine.GetLength();
	
	for(int i=0;i<len;i++){
		if(flag){//处于非分隔区
			if(StrLine.GetAt(i)==Fgf){
				ColValues.Add(StrLine.Mid(p1,i-p1));
				flag = false;
			}
		}else{//处于分隔区
			if(StrLine.GetAt(i)!=Fgf){
				p1 = i;
				flag = true;
			}
		}
	}
	ColValues.Add(StrLine.Mid(p1,len-p1));

}


-- memcpy)详解           https://blog.csdn.net/iamzhangzhuping/article/details/50570951 

 
  
  
  memcpy用来做内存拷贝，你可以拿它拷贝任何数据类型的对象，可以指定拷贝的数据长度；

例：

　　char a[100], b[50];

　　memcpy(b, a,sizeof(b)); //注意如用sizeof(a)，会造成b的内存地址溢出。

　　strcpy就只能拷贝字符串了，它遇到'\0'就结束拷贝；例：

　　char a[100], b[50];


   
  
  
  
  --  f:\work\code\SLGem\SLRDTL\ModelGraph\ReserviorModelDynamicModelGraph.cpp 
  
  void ReserviorModelDynamicModelGraph::FindDataPath( CString path,CString Mark,vector<CString> &CaseNameList )
{
	CString myDataPath,fdPath;
	myDataPath=path + _T("\\*.*");
	CString strTmp;

	CFileFind find;
	BOOL bf = find.FindFile(myDataPath);
	while(bf)
	{                        
		bf = find.FindNextFile();
		if(!find.IsDots())
		{
			fdPath=find.GetFilePath();
			if (find.IsDirectory())
			{
				//如果是文件夹，递归，继续往下找                        
				FindDataPath(fdPath,Mark,CaseNameList);
			}
			else
			{
				//如果是文件,判断是否是*.txt
				strTmp=fdPath.Right(Mark.GetLength());

				strTmp.MakeLower();
				if ( strTmp==Mark)
				{
					int nPos = fdPath.ReverseFind('\\');
					CString str = fdPath.Right(fdPath.GetLength()-nPos-1);
					nPos = str.ReverseFind('.');
					CaseNameList.push_back(str.Left(nPos));
				}
			}
		}
	}
	find.Close();
}
 
  
  
  --   sort 排序（降序、升序） https://blog.csdn.net/zhangpiu/article/details/50564064 
sort(begin(vec),end(vec));
  
  二、降序
    降序排序的方法与升序类似，如果采用比较函数、Lambda 或者比较函数的方式，只需要改一改比较条件就OK了，但是，如果对于Student类，我们定义了 operator < 之后，不想为了降序排序再定义一个 operator > 怎么办？两种办法！
2.1 reverse
    升序排序之后，用 reverse 反转即可。

  
  
  
  
  
  --  __declspec(dllimport)   https://www.cnblogs.com/nzbbody/p/3448385.html 
  
  理解 __declspec(dllexport)和__declspec(dllimport)
1、解决的问题：

　　考虑下面的需求，使用一个方法，一个是提供者，一个是使用者，二者之间的接口是头文件。头文件中声明了方法，在提供者那里方法应该被声明为__declspec(dllexport)，在使用者那里，方法应该被声明为__declspec(dllimport)。二者使用同一个头文件，作为接口，怎么办呢？

2、解决办法：

　　使用条件编译：定义一个变量，针对提供者和使用者，设置不同的值。

  #ifndef DLL_H_
#define DLL_H_

#ifdef DLLProvider
#define DLL_EXPORT_IMPORT __declspec(dllexport)
#else
#define DLL_EXPORT_IMPORT __declspec(dllimport)
#endif

DLL_EXPORT_IMPORT int add(int ,int);

#endif
  
  
  
  
  -- void * (void)*  https://zhidao.baidu.com/question/422255015.html 
  
  void* 这个说明返回值为void指针。
void(*)这个表示此函数为指针函数。 
  
  
  
  
  
  
  
  
  
  
  --  AFX_MANAGE_STATE(AfxGetStaticModuleState())   https://blog.csdn.net/optman/article/details/332277 
  
  
  
  
  
 -- GetPrivateProfileInt 使用方法  https://blog.csdn.net/jixuxiangqianzou/article/details/9070147 
  
  GetPrivateProfileInt ＝＞从ini文件取得数值
　＜参数＞
　　lpApplicationName String， 指定在其中查找条目的小节。注意这个字串是不区分大小写的 
　　lpKeyName String，欲获取的设置项或条目。这个支持不区分大小写 
　　nDefault Long， 指定条目未找到时返回的默认值 
　　lpFileName String，初始化文件的名字。如果没有指定完整的路径名，windows就会在Windows目录中搜索文件


  
  -- WritePrivateProfileString  https://blog.csdn.net/wuguai4/article/details/7287346 
  
  
  
   
  
  
  --   用c++怎样判断一个数字的数据类型       https://zhidao.baidu.com/question/751045683572435724.html 
  
  
  #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;
#include <typeinfo>

int main(void){

	int a=0;  
	float b=0.2;  
	char c='s';  
	int *d=NULL;
	cout <<typeid(a).name()<<endl;  
	cout <<typeid(b).name()<<endl;
	cout <<typeid(c).name()<<endl;  
	cout <<typeid(d).name()<<endl;  

	if (typeid(a) == typeid(int))
		cout << "a's type is int" <<endl;

	getchar();
	return 0;
}
  
  
  
  
  
  
  void CParamSelectDlg::OnEnKillfocusEdit4()
{
	CString cstrText = "";

	m_cTextEdit.GetWindowText( cstrText );

	if (m_nCol == 3 ) // minimum value 
	{
		CString CSTemp;
		CSTemp = m_ParamList.GetItemText( m_nRow, m_nCol-1 );
		if ( atof(CSTemp) < atof(cstrText) )
		{
			AfxMessageBox(_T("最小值不能大于最大值!"));
			return;
		}
	}
	
	m_ParamList.SetItemText( m_nRow, m_nCol, cstrText );

	m_cTextEdit.ShowWindow(SW_HIDE);
}

  
  
  


 












 

   
  
  
  
  
  
   
  
  
  
  
  
  
  
  
  
  
  
  
  
   
  
  
  
  
  
  
  
  
   
  