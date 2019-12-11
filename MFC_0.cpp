

 NM_CLICK  https://blog.csdn.net/pipi0714/article/details/23439861 
 
 
 
 
  cstring去除最后三个字符  https://zhidao.baidu.com/question/429840606514328332.html 
 
 
 CString str1="asdfadsfasf";
str1.Left(str1.GetLength() - 1);
//CString友好多方法时对字符串操作的，看看msdn就明白了




--  CString的库函数截取字符串中间的一段   https://zhidao.baidu.com/question/286475488.html  

例如 CString str = _T("http://www.baidu.com/.....xxx.jpg?ateccgderggdsfdafa");
我想截取jpg  就是最后一个.和？之间的字符串
该如何实现？

 CString str = _T("http://www.baidu.com/.....xxx.jpg?ateccgderggdsfdafa");

	str = str.Left(str.Find('?'));
	str = str.Right(str.GetLength()-1-str.ReverseFind('.'));
	AfxMessageBox(str);
	
	
	
	
cstring从右裁剪掉指定字符后的字符串?保留指定字符前的cstring? 	  https://zhidao.baidu.com/question/329256649.html 
	
	CString str;
CString Tmp = “abcddef”;
CString res;
res = str.left(4);  // res 就等于 abcd
保留指定字符前的cstring也是一样
先用int n = Tmp.find("d"); //n就等于3。（从0开始计数，d是第3个字符）
然后再res  = str.left(n); //res 就取str左侧3个字符，即abc。这时的3是指3个，不是索引 
你用追问啊。补充提问我有时没看到，从后面找可以使用  ReverseFind()，用法和 find() 是一样的，只不过这个是从后面开始查找
int n = Tmp.ReverseFind("d");
返回的n就是后的一个d的索引位置，然后str.left(n+1)就把你这个d后面的全部去掉了
	
 
	
	
	
	
	--  CString 与int、float之间的转换    https://blog.csdn.net/lh1573378488/article/details/52767066 
	
	CString to float: 
如下：

CString str="1.2";
float f;
f = atof(str);
	
	
	
-- 
	
	 
	 请问如何判断cstring中包含一个子串-CSDN论坛   https://bbs.csdn.net/topics/70239964 

	
	
	 str.Find("asdf"); 
	
	
	
	
MFC_MSFlexGrid基本使用 		 https://wenku.baidu.com/view/899f313cfc4ffe473268ab1d.html 	
	  http://www.chinadmd.com/file/we6seprzvp3tciouae3i6zcv_1.html 


m_FlexGrid.SetColAlignment(1,4); //设置列号为 1的文本对齐方式 参数对应描述为:
0 单元内容顶部左对齐。
1 单元内容中间左对齐。对字符串的缺省设置值。
2 单元内容底部左对齐。
3 单元内容顶部居中。
4 单元内容中间居中。 
	
	
    m_FlexGrid.SetTextMatrix(1,1,"Text");  	 //设置单元格（行号1列号1）内容为“Text”


 隐藏列  https://bbs.csdn.net/topics/330076438 
	
	
	MsFlexGrid好像没有隐藏列的功能。
你用SetColWidth(nCol, 0)还有SetColAlignment(nCol, 0)； 
	

	--  Expression:(“Incorrect format specifier”,0)错误 http://www.youranshare.com/push/code/win-c-cpp/550.html 
	
	 incorrect format specifier  
	
	


-- __atl_condVal 





--  CTime类格式化时间的时候总是出错 https://zhidao.baidu.com/question/474590949.html 




CString date = time.Format("%Y-%m-%d %H:%M:%S %W-%A"); 









 

--  DoDataExchange错误   https://bbs.csdn.net/topics/390943065 




 --  文本框为只读状态  https://blog.csdn.net/friendan/article/details/7303615 

 
CEdit *pEditUser=NULL;
 pEditUser=(CEdit *)GetDlgItem(IDC_EDIT_OLDNAME);    //获取文本框指针
 pEditUser->SetReadOnly(TRUE);                                      //设置为只读状态 



--    CTreeCtrl  根据名称查找节点  https://blog.csdn.net/shenhch/article/details/78606033 

  HTREEITEM  finditem(HTREEITEM  item, CString strtext)   
{  
    HTREEITEM  hfind;  
    //空树，直接返回NULL
    if(item ==  NULL)  
        return  NULL;  
    //遍历查找
    while(item!=NULL)  
    {  
        //当前节点即所需查找节点
        if(m_Tree.GetItemText(item) == strtext)  
            return   item;  
        //查找当前节点的子节点
        if(m_Tree.ItemHasChildren(item))  
        {  
            item   =   m_Tree.GetChildItem(item); 
            //递归调用查找子节点下节点
            hfind   =   finditem(item,strtext); 
            if(hfind)  
            {  
                return  hfind;  
            }  
            else   //子节点中未发现所需节点，继续查找兄弟节点
            {
                item = m_Tree.GetNextSiblingItem(m_ShowObjectTree.GetParentItem(item));  
            }
        }  
        else{   //若无子节点，继续查找兄弟节点
            item = m_Tree.GetNextSiblingItem(item);  
        }  
    }  
    return item;  
}



-- 菜单显示的文字  https://blog.csdn.net/li_canhui/article/details/6636101    不要用  LoadMenuA  用： LoadMenu

CMenu *cMenu = new CMenu();
cMenu->LoadMenuA(IDR_MENU1);//加载菜单，IDR_MENU1是整个菜单资源的ID		
CMenu *subMenu = cMenu->GetSubMenu(0);//获取菜单中的第一个菜单
/*MF_BYPOSITION (by position )表示修改第0个位置的菜单项*/
subMenu->ModifyMenuA(0, MF_BYPOSITION, ID_CONFIG, "Configuration");//将第一个菜单下的第一个菜单项的文字改为“Configuration” 




	m_ProjectListTree.Select(CurrentItem,TVGN_CARET);//设置点击节点为当前选中节点
			CMenu m,*mn;
			m.LoadMenu(IDR_MENU_DEP_EW_TREE_POPUP);//加载菜单资源
			mn = m.GetSubMenu(0);//获取菜单子项
			mn->TrackPopupMenu(TPM_LEFTALIGN,ptSc.x,ptSc.y,this);    //显示菜单	

 


str.Format(_T("Production of Existing well before%d \n%d年底前投产井产量"),m_Year,m_Year);
		Data.push_back(str);




-- 修改主菜单和子菜单的文本  https://blog.csdn.net/u013317006/article/details/17657027 




// ======= 更新菜单 ===================================
CMenu *subMenu = this->GetMenu()->GetSubMenu(0);
//更改主菜单
    this->GetMenu()->ModifyMenu(0,MF_BYPOSITION,IDMENU_3,   _T("修"));
this->GetMenu()->ModifyMenu(1,MF_BYPOSITION,IDMENU_4e,   _T("最"));
this->GetMenu()->ModifyMenu(2,MF_BYPOSITION,IDMENU_4t,   _T("fd"));
this->GetMenu()->ModifyMenu(3,MF_BYPOSITION,IDMENU_G5de,   _T("ds"));
//以上的ID，需要手动增加到资源文件。
//更改子菜单
subMenu->ModifyMenu(IDMENU_1, MF_BYCOMMAND, IDMENU_OpenSource, _T("dsasad"));
subMenu->ModifyMenu(IDMENU_2 MF_BYCOMMAND, IDMENU_OpenTarget, _T("dsa"));
subMenu->ModifyMenu(IDMENU_SaveFileAll, MF_BYCOMMAND, IDMENU_SaveFileAll, _T("dsa"));
subMenu = this->GetMenu()->GetSubMenu(1);
subMenu->ModifyMenu(MENU_FILE1, MF_BYCOMMAND, MENU_FILE1, _T("dsa:")); 






ID_EW_YERA  ID_EW_NEXT_YEAR 


 
 --   CDateTimeCtrl  https://bbs.csdn.net/topics/340248762
  
  CDateTimeCtrl*  pTime  = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
    ASSERT(pTime);
     CTime   timeTime(2009, 1, 11, 0, 0, 0);
    pTime->SetTime(&timeTime); 

 -- CDateTimeCtrl  https://blog.csdn.net/timothy721/article/details/8809316
// 绑定空间的成员：
     CDateTimeCtrl m_dateBegin; //日期
    CDateTimeCtrl m_timeBegin;//时间
	
    COleDateTime  currOleDate;
    m_dateEnd.GetTime(currOleDate);
    COleDateTime oleDate;
    oleDate.SetDate(currOleDate.GetYear() - 1, currOleDate.GetMonth(), currOleDate.GetDay());  
    m_dateBegin.SetTime(oleDate);   

    COleVariant vtime("0:00:00");//设定时间控件时间信息
    vtime.ChangeType(VT_DATE);
    COleDateTime oleTime=vtime;
    m_timeBegin.SetTime(oleTime);


	
	
	--   分割成字符串数组可以做到吗?  https://bbs.csdn.net/wap/topics/270016668
	CString str="acx|bxd|yzs|pes"; 
	  char *csInput; 

	csInput=str.GetBuffer(str.GetLength()); //提取字符串，把单词存放在数组csInput中 
	char seps[]= "|";                              //字符串以|为分隔符 
		char *token; 

	token = strtok( csInput, seps ); 
	index=0;          //全局变量 
	  while( token != NULL )                    //把提取到的单词存放到数组csEditIput中 
		{ 
			csEditInput[index]=token;                /* 把单词存放在数组csEditInput中" */ 
	index++; 
			token = strtok( NULL, seps );          /* Get next token: */ 
		}




--  tokenize 和 split 函数 https://blog.csdn.net/educast/article/details/10739751 
	
	
	int main(void)  
{  
 CString s = ",ab;cde,f,,;gh,,";  
 CString sub = ",;";  
 CStringList list1,list2;  
  
   
 Tokenize(s,sub,&list1,TRUE,"no use"); // <-----  
 printf("-------[Tokenize_trim]-------/n");  
 POSITION pos1 = list1.GetHeadPosition();  
 while( pos1!= NULL )  
 {  
  printf( list1.GetNext(pos1) );  
  printf("/n");  
 }  
 Tokenize(s,sub,&list2,FALSE,"[null]"); // <-----  
 printf("------[Tokenize_no_trim]-----/n");  
 POSITION pos2 = list2.GetHeadPosition();  
 while( pos2!= NULL )  
 {  
  printf( list2.GetNext(pos2) );  
  printf("/n");  
 }  
   
 CStringList list3;  
 s = "###0123###567######89###1000###";  
 sub = "###";  
 Split(s,sub,&list3, 3, "<null>"); // <-----  
 printf("------[Split]-----/n");  
 POSITION pos3 = list3.GetHeadPosition();  
 while( pos3!= NULL )  
 {  
  printf( list3.GetNext(pos3) );  
  printf("/n");  
 }  
 return 0;   
} 
	
	
-- CString 与 CStringArray 互相转化  https://www.cnblogs.com/greatverve/archive/2010/11/08/cpp-cstring-cstringarray.html 

//类似C#的Split('_');DivStr(str,strArr,_T("_"));
UINT DivStr(CString str,CStringArray& Arr,char ch)
{
    int nFindposi  = str.Find(ch);
    if( nFindposi <0 )
        return 0;

    while( nFindposi > 0)
    {
        Arr.Add(str.Left(nFindposi) );
        str = str.Right( str.GetLength() - nFindposi -1);
        str.TrimLeft(ch);    //warning

        nFindposi  = str.Find(ch);
    }

    if( !str.IsEmpty() )
        Arr.Add(str);

    return Arr.GetSize();
}

UINT DivStr(CString str,CStringArray& Arr,CString strDiv)
{
    int nFindposi  = str.Find(strDiv);
    if( nFindposi <0 )
        return 0;

    while( nFindposi > 0)
    {
        Arr.Add(str.Left(nFindposi) );
        str = str.Right( str.GetLength() - nFindposi -1);
        str.TrimLeft(strDiv);    //warning

        nFindposi  = str.Find(strDiv);
    }

    if( !str.IsEmpty() )
        Arr.Add(str);

    return Arr.GetSize();
}
void CCStringArrayDlg::OnBnClickedButtonOk()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str = m_str;//_T("i am a student");
    CStringArray strArr;
    //CString转CStringArray
    if( DivStr(str,strArr,_T(" ")) <= 0)
    {
        AfxMessageBox( _T("数组为空!"));
        return;
    }
    //CStringArray转CString
    str = _T("");
    int index =strArr.GetSize();
    for(int i=0;i<index;i++)
    {
        str += strArr[i]+_T("_");
    }
    m_str = str.TrimRight('_');
    UpdateData(false);
}
	
	
	
	-- combobox设成只读的简单方法    http://blog.163.com/larnya@126/blog/static/4891779420093181034578/ 
	
	((CEdit*)m_combobox.GetWindow(GW_CHILD))->SetReadOnly(); 

	
--  删除 CTreeCtrl 中某个节点的子节点 https://blog.csdn.net/u012372584/article/details/58585302 

void CFileView::DelAllChildOfItem(HTREEITEM hItem)
{
	BOOL bRet=FALSE;
	HTREEITEM hChildItem=NULL;
	while (TRUE)
	{
		bRet= m_Tree.ItemHasChildren(hItem);
		if (!bRet)//没有孩子
		{
			break;
		} 
		else
		{
			hChildItem=m_Tree.GetChildItem(hItem);
			m_Tree.DeleteItem(hChildItem);
		}
	}
	return;
 
	/*
	方法二：
	if (m_Tree.ItemHasChildren(hItem))
	{
		HTREEITEM hNextItem=NULL;
		HTREEITEM hChildItem=m_Tree.GetChildItem(hItem);
		while (hChildItem!=NULL)
		{
			hNextItem=m_Tree.GetNextItem(hChildItem,TVGN_NEXT);
			m_Tree.DeleteItem(hChildItem);
			hChildItem=hNextItem;
		}
	}
	*/
}



--  CComboBox 的列表中我放置了许多项，但它会自动排序，如何能够不要系统进行排序     https://bbs.csdn.net/topics/260033927      https://blog.csdn.net/feiyang094/article/details/42613781 

ComboBox properties 下面的style里面去掉 Sort 全面的勾 

在界面上把属性中的sort去掉或者设置属性的时候去掉自动排序功能。
另外，建议你把Please Select:这个放在外面比较好。




--  BCGCBProInc.h : No such s file or dictionary  https://blog.csdn.net/hqyhqyhq/article/details/8291317


  




bcgcontrolbarpro    https://www.bcgsoft.com/download.htm 



-- AfxGetApp   https://blog.csdn.net/tianmeshi/article/details/4209904 

AfxGetApp( )是全局的。
AfxGetApp( )这个函数可以得到当前应用进程的指针，是 CWinApp*类型的，通过这个指针可以访问到这个进程中的对象。
比如在全局函数中要向对话框中的列表写数据。


d writeString(char* pString)

｛

   CWnd* pWnd = AfxGetApp()->GetMainWnd();
   CMyDlg * pDlg;
   pDlg=(CMyDlg *) pWnd;
   pDlg->ShowMsg(pString);

｝



-- lpstrInitialDir   https://blog.csdn.net/luoweifu/article/details/24672347
 
 
 
 
 
 -- https://www.cnblogs.com/yzl050819/p/6019166.html 
 
   
2;输出列表 
就是需要输出的一些数据,也可以是表达式,如果在函数中需要输出多个变量或表达式,则要用逗号隔开. 
 一些特殊字符的输出： 
单引号，双引号，和反斜杠的输出在前面加转义字符”\” 
如：”\’” , “\”” , “\\” 
%的输出用两个连在一起的%%，即printf(“%%”);  



-- HTREEITEM 通过名称获取   https://blog.csdn.net/giantchen547792075/article/details/22484297 
 
  // name - the name of the item that is searched for
// tree - a reference to the tree control
// hRoot - the handle to the item where the search begins
HTREEITEM FindItem(const CString& name, CTreeCtrl& tree, HTREEITEM hRoot)
{
   // check whether the current item is the searched one
   CString text = tree.GetItemText(hRoot);
   if (text.Compare(name) == 0)
      return hRoot; 
 
   // get a handle to the first child item
   HTREEITEM hSub = tree.GetChildItem(hRoot);
   // iterate as long a new item is found
   while (hSub)
   {
      // check the children of the current item
      HTREEITEM hFound = FindItem(name, tree, hSub);
      if (hFound)
         return hFound; 
 
      // get the next sibling of the current item
      hSub = tree.GetNextSiblingItem(hSub);
   } 
 
   // return NULL if nothing was found
   return NULL;
}
 
 HTREEITEM CTreeDemoDlg::FindItem(const CString& name, CTreeCtrl& tree)
{
   HTREEITEM root = m_tree.GetRootItem();//m_tree是成员变量，即当前要搜索的树形控件
   while(root != NULL)
   {
      HTREEITEM hFound = FindItem(name, tree, root);
      if (hFound)
         return hFound; 
 
      root = tree.GetNextSiblingItem(root);
   }
 
   return NULL;
}

 
 --  error C2864:只有静态常量整型数据成员才可以在类中初始化 https://blog.csdn.net/cxhply/article/details/49584005 
  visual Studio 2010不支持      可用class替换struct实现类定义 
 
 
 
  HTREEITEM  InsertItem  -- 

void CDataManageTemplateView::InitDepDataProTree( HTREEITEM hRoot )
{
	HICON hIcon[3];      // 图标句柄数组   
	//HTREEITEM hRoot;     // 树的根节点的句柄   
	HTREEITEM hCompanyItem; // 可表示任一分类节点的句柄   
	HTREEITEM hEntityItem;  // 可表示任一文章节点的句柄   
	HTREEITEM hBlockItem;  // 可表示任一文章节点的句柄   
	HTREEITEM hProjectItem;  // 可表示任一文章节点的句柄   

	CString Sql = _T("SELECT DISTINCT COMPANYNAME FROM TMP_DEP_HEADER ");
	vector<vector<CString>> RootResult;
	vector<vector<CString>> CataItemResult;
	vector<vector<CString>> ArtItemResult;
	vector<vector<CString>> ProjectCodeResult;
	if(theApp.m_projManager.ExecuteQuery(Sql,RootResult))
	{
		for(int iRoot=0;iRoot<RootResult.size();iRoot++)
		{
			hCompanyItem = m_ProjectListTree.InsertItem(RootResult[iRoot][0],0,0,hRoot,TVI_LAST);
			Sql.Format(_T("SELECT DISTINCT ENTITY FROM TMP_DEP_HEADER  WHERE COMPANYNAME = '%s'"),RootResult[iRoot][0]);
			if(theApp.m_projManager.ExecuteQuery(Sql,CataItemResult))
			{
				for(int iCataItem=0;iCataItem<CataItemResult.size();iCataItem++)
				{
					hEntityItem = m_ProjectListTree.InsertItem(CataItemResult[iCataItem][0], 1, 1, hCompanyItem, TVI_LAST);
					Sql.Format(_T("SELECT DISTINCT BLOCK FROM TMP_DEP_HEADER  WHERE ENTITY = '%s' AND COMPANYNAME = '%s'"),CataItemResult[iCataItem][0],RootResult[iRoot][0]);
					if(theApp.m_projManager.ExecuteQuery(Sql,ArtItemResult))
					{
						for(int iArtItem=0;iArtItem<ArtItemResult.size();iArtItem++)
						{
							hBlockItem = m_ProjectListTree.InsertItem(ArtItemResult[iArtItem][0], 1, 1, hEntityItem, TVI_LAST);
							Sql.Format(_T("SELECT DISTINCT PROJECTCODE FROM TMP_DEP_HEADER WHERE BLOCK = '%s' AND ENTITY = '%s' AND COMPANYNAME = '%s'")
								,ArtItemResult[iArtItem][0],CataItemResult[iCataItem][0],RootResult[iRoot][0]);
							if(theApp.m_projManager.ExecuteQuery(Sql,ProjectCodeResult))
							{
								for(int iproject=0;iproject<ProjectCodeResult.size();iproject++)
								{
									hProjectItem = m_ProjectListTree.InsertItem(ProjectCodeResult[iproject][0], 1, 1, hBlockItem, TVI_LAST);
									InitDepProjectListTree(hProjectItem);
								}
							}	
						}
					}
				}
			}
		}
	}
}
 
 
 
 
  NMHDR    Notify   Message   Handler 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
   




 
