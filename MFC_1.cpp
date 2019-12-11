
-- CTreeCtrlEx树控件完整多选  https://blog.csdn.net/wang15061955806/article/details/52299487 



--  修改树状控件TreeCtrl的节点名称   http://www.xuebuyuan.com/1703046.html


afx_msg void OnBeginlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult);  //开始编辑
afx_msg void OnEndlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult);   //结束编辑

void CPMAgentManageDlg::OnBeginlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_TreeCtrl.GetEditControl()->LimitText(1024);
	*pResult = 0;
}

void CPMAgentManageDlg::OnEndlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM m_hInsertItem;
	CString strName; //修改后的数据
	m_TreeCtrl.GetEditControl()->GetWindowText(strName);
	if (strName.IsEmpty())
	{
		MessageBox("数据项名称不能为空，请重新输入!");
		CEdit *pEdit = m_TreeCtrl.EditLabel(m_hInsertItem);
		return;
	}
	if (strName == g_sSelectStr)
	{
		return;
	}
 	HTREEITEM hRoot = m_TreeCtrl.GetRootItem();
 	HTREEITEM hFind = FindItem(hRoot,strName);          //判断数据是否相同
	if (hFind == NULL)
	{
		char msg[64]={0};
		sprintf(msg,"修改信息为%s,确定吗?",strName);
		if (MessageBox(msg,"提示",MB_OKCANCEL) == IDOK)
		{
			CString strText;
			m_TreeCtrl.GetEditControl()->GetWindowText(strText.GetBuffer(200),200);
			m_TreeCtrl.SetItemText(m_TreeCtrl.GetSelectedItem(),strText);//设置编辑后的文本为结点
			*pResult = TRUE;

		}
		else
		{
			m_TreeCtrl.DeleteItem(m_hInsertItem);
		}
	}
	else //找到相同数据
	{
		if ((g_sSelectStr == "北京一区") || (g_sSelectStr =="矩阵地址") || (g_sSelectStr =="服务端口") )
		{
			MessageBox("该数据已存在");
			CEdit *pEdit = m_TreeCtrl.EditLabel(m_hInsertItem);
		}
		else
		{
			char msg[64]={0};
			sprintf(msg,"修改信息为%s,确定吗?",strName);
			if (MessageBox(msg,"提示",MB_OKCANCEL) == IDOK)
			{
				CString strText;
				m_TreeCtrl.GetEditControl()->GetWindowText(strText.GetBuffer(200),200);
				m_TreeCtrl.SetItemText(m_TreeCtrl.GetSelectedItem(),strText);//设置编辑后的文本为结点
				*pResult = TRUE;
				

			}
			else
			{
				m_TreeCtrl.DeleteItem(m_hInsertItem);
			}
		}
	}
	*pResult = 0;
}



--  CListCtrl控件的标题栏添加checkbox  https://blog.csdn.net/challenge00/article/details/37741015  


 1创建CListCtrl控件，并设置其风格为checkbox; 
首先设置CListCtrl的风格，让每一列最前面出现勾选框。

（注：本文使用的CListCtrl的申明为：CListCtrl m_searchresultlist; ）

m_searchresultlist.SetExtendedStyle(m_searchresultlist.GetExtendedStyle()|LVS_EX_CHECKBOXES);



2为标题栏添加一个checkbox

    首先要添加checkbox的BMP资源文件，在对话框初始化创建一个包含这个bitmap的image list ，然后将这个imagelist添加到标题栏。

	
	 //在表头上添加checkbox

    /*CHeaderCtrl* */
	pHeadCtrl =m_searchresultlist.GetHeaderCtrl();
    ASSERT(pHeadCtrl->GetSafeHwnd());
    VERIFY(m_checkImgList.Create(IDB_CHECKBOXES, 16, 3, RGB(255,0,255)));
    int i = m_checkImgList.GetImageCount();
    pHeadCtrl->SetImageList(&m_checkImgList); 
    HDITEMhdItem;
    hdItem.mask= HDI_IMAGE | HDI_FORMAT;
    VERIFY(pHeadCtrl->GetItem(0, &hdItem) );
    hdItem.iImage= 1;
    hdItem.fmt|= HDF_IMAGE;
    VERIFY(  pHeadCtrl->SetItem(0, &hdItem) );
	return TRUE;  // return TRUE unless you set the focus to a control
	
	
	
	
	
  



-- CListCtrl全选、反选  https://blog.csdn.net/sniper08/article/details/5521822 



// 全选
void CMFC_ListViewDlg::OnBnClickedButtonSelectAll()
{
 for (int i = 0; i < m_listCtrl.GetItemCount(); i++)
 {
  m_listCtrl.SetItemState(i,LVIS_SELECTED, LVIS_SELECTED);
 }
 m_listCtrl.SetFocus(); // 将焦点设置回ListCtrl
}

 

// 反选
void CMFC_ListViewDlg::OnBnClickedButton1()   
{
 // TODO:   在此添加控件通知处理程序代码   
 for (int i=0; i < m_ListCtrl.GetItemCount(); i++)   
 {
  if (this->m_ListCtrl.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
  {
   this->m_ListCtrl.SetItemState(i, 0, LVIS_SELECTED);
  }
  else
  {
   this->m_ListCtrl.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
  }
 }
}




--  设置按钮的文字/改变按钮的文字 https://blog.csdn.net/niusiqiang/article/details/43116077 


（1）获取按钮的文本具体示例如下：

//用于缓冲的临时CString

CStringtempstr;

//获取ID_SimPause按钮的文本内容，其中ID_SimPause为按钮的ID

GetDlgItem(ID_SimPause)->GetWindowText(tempstr);

（2）设置按钮的文本具体示例如下：

//，其中ID_SimPause为按钮的ID,””内为按钮的文字内容

GetDlgItem(ID_SimPause)->SetWindowText("仿真恢复"); 




 


	--  CListCtrl）可编辑 https://jingyan.baidu.com/article/e75057f2f438f8ebc91a89a7.html 


三、在对话框的OnInitDialog初始化函数中添加如下代码（对列表控件进行初始化）：

m_lstcoudata.InsertColumn(0,"课程名称",LVCFMT_CENTER,100);

m_lstcoudata.InsertColumn(1,"是否主科",LVCFMT_CENTER,100);

m_lstcoudata.InsertColumn(2,"周课时",LVCFMT_CENTER,100);

m_lstcoudata.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

m_lstcoudata.SetBkColor(RGB(172,199,235));

m_lstcoudata.SetRowHeigt(40);

m_lstcoudata.SetFontHW(15,10);

GRADE *pgrd=CArrangeCourseApp::Adu .GetGrdPointer()->pnext;

for(int n=0;n<10;n++)

  m_lstcoudata.InsertItem(n,"");

 

 //ect rc;

 m_lstcoudata.GetClientRect(&rc);

 m_lstcoudata.SetColumnWidth(0,rc.Width()/2);

 m_lstcoudata.SetColumnWidth(1,rc.Width()/4);

 m_lstcoudata.SetColumnWidth(2,rc.Width()/4);
 



四、下面我们要在鼠标对列表控件的单击事件中，将需要显示的控件移动到鼠标单击的单元格中。代码如下：

NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;

        CRect rc;

        if(pNMListView->iItem==-1)return;

        m_row=pNMListView->iItem;//m_row为被选中行的行序号（int类型成员变量）

   m_column=pNMListView->iSubItem;//m_column为被选中行的列序号（int类型成员变量）

if(m_column!=2)return;

//if(m_column<0)return;

        UpdateData(TRUE);

   m_lstcoudata.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//取得子项的矩

  rc.left+=150;

  rc.right+=150;

  rc.bottom+=100;

  m_cmbcnt.ShowWindow(SW_SHOW);

           m_cmbcnt.MoveWindow(&rc);

           m_cmbcnt.SetFocus();

*pResult = 0;


--  ListCtrl的项中通过单击获得文本输入或更改项目中的文本  https://bbs.csdn.net/topics/322922 

首先需要设置列表控件的LVS_EDITLABELS风格
//处理消息 LVN_BEGINLABELEDIT
void CParentWnd::OnBeginEditList(NMHDR* pNMHDR, LRESULT* pResult)
{
LV_DISPINFO* pLVDI = (LV_DISPINFO*)pNMHDR;
if(pLVDI->item.iItem==0);//判断是否取消该操作
*pResult = 1;
else
*pResult = 0;
}
//处理消息 LVN_BEGINLABELEDIT
void CParentWnd::OnBeginEditList(NMHDR* pNMHDR, LRESULT* pResult)
{
LV_DISPINFO* pLVDI = (LV_DISPINFO*)pNMHDR;
if(pLVDI->item.pszText==NULL);//判断是否已经取消取消编辑
m_list.SetItemText(pLVDI->item.iItem,0,pLVDI->pszText);//重置显示字符
*pResult = 0;
}



--  为CListCtrl添加item编辑功能  https://blog.csdn.net/chenlycly/article/details/17190605 


 AlterColValue
  
、在dlg窗体添加一个 CListCtrl 和一个 CEdit
2、为此两控件对应绑定两成员变量，如下
CListCtrl m_List;
CEdit m_cTextEdit;
3、在dlg.h头文件添加两似有成员变量
private:
 int m_nRow;
 int m_nCol;

4、在 oninitdialog 初始化化 listctrl 和 edit
 // 设置接收文件列表风格
 LONG lStyle;
 lStyle = GetWindowLong(m_List.m_hWnd, GWL_STYLE);
 lStyle |= LVS_REPORT; 
 SetWindowLong(m_List.m_hWnd, GWL_STYLE, lStyle);

 DWORD dwStyle = m_List.GetExtendedStyle();
 dwStyle |= LVS_EX_FULLROWSELECT; 
 dwStyle |= LVS_EX_GRIDLINES; 
 m_List.SetExtendedStyle(dwStyle);  
 
 // 初始化列表头信息
 m_List.InsertColumn( em_LIST_ITEM_KEY, "Key", LVCFMT_LEFT, 140 );
 m_List.InsertColumn( em_LIST_ITEM_VALUE, "Value", LVCFMT_LEFT, 200 );

 m_cTextEdit.ShowWindow( SW_HIDE );

5、为CListCtrl添加双击事件处理	NM_DBLCLK 		https://www.cnblogs.com/hongfei/archive/2012/12/25/2832806.html 
void CXXXDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
 // TODO: Add your control notification handler code here
 char ach[MAX_LISTITME_LEN] = {0};
 CRect cRectItem;
 CRect cRectList;

 NM_LISTVIEW* pNMListView = ( NM_LISTVIEW* )pNMHDR;
 
 if ( -1 != pNMListView->iItem )
 {
  m_nRow = pNMListView->iItem; 
  m_nCol = pNMListView->iSubItem;

  //过滤key，key不允许修改
  if ( 0 == m_nCol)
  {
   *pResult = 0;
   return;
  }

  m_List.GetSubItemRect( pNMListView->iItem, pNMListView->iSubItem, LVIR_LABEL, cRectItem ); 
  m_List.GetWindowRect( &cRectList );
  ScreenToClient( &cRectList );

  cRectItem.left   += cRectList.left + 3;
  cRectItem.top    += cRectList.top;
  cRectItem.right  += cRectList.left + 3;
  cRectItem.bottom += cRectList.top + 3;

  m_List.GetItemText( pNMListView->iItem, pNMListView->iSubItem, ach, MAX_LISTITME_LEN); 
  m_cTextEdit.SetWindowText( ach ); 
  m_cTextEdit.ShowWindow( SW_SHOW ); 
  m_cTextEdit.MoveWindow( &cRectItem ); 
  m_cTextEdit.SetFocus(); 
  m_cTextEdit.CreateSolidCaret( 1, cRectItem.Height() - 5 );
  m_cTextEdit.ShowCaret(); 
  m_cTextEdit.SetSel( -1 );

 }

 *pResult = 0;
}


6、为 m_cTextEdit 添加光标消失事件处理
void CXXXDlg::OnKillfocusEditText() 		killFocus 
{
 // TODO: Add your control notification handler code here
 CString cstrText = "";

 m_cTextEdit.GetWindowText( cstrText );
 m_List.SetItemText( m_nRow, m_nCol, cstrText );

 m_cTextEdit.ShowWindow(SW_HIDE);
}

7、结束.

 
 
 
 
 --    双击 MsFlexGrid 控件的单元格时，显示编辑框，但是如何精确定位编辑框在MsFlexGrid控件中的位置呢？   http://zhichengma2007.blog.163.com/blog/static/5892162920091124573316/ 
 
 
    CRect cRectItem;

	char ach[20] = {0};

	CRect rect; 
	m_ParamListGrid.GetWindowRect(rect); 
	ScreenToClient(rect); 
	long lRow = m_ParamListGrid.GetRowSel(); 
	long lCol = m_ParamListGrid.GetColSel(); 

	m_nRow= lRow;
	m_nCol =lCol;
	// MSFlexGrid 控件的函数的长度单位是"缇(twips)"， 
	//需要将其转化为像素，1440 缇 = 1 英寸 
	CDC* pDC =GetDC(); 
	int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ; 
	int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ; 
	// 
	long y = m_ParamListGrid.GetRowPos(lRow)/nTwipsPerDotY; 
	long x = m_ParamListGrid.GetColPos(lCol)/nTwipsPerDotX; 
	long width = m_ParamListGrid.GetColWidth(lCol)/nTwipsPerDotX+1; 
	long height = m_ParamListGrid.GetRowHeight(lRow)/nTwipsPerDotY+1; 
	CRect rc(x,y,x+width,y+height); 
	rc.OffsetRect(rect.left+1,rect.top+1); 

	CString str=m_ParamListGrid.GetTextMatrix(m_nRow,m_nCol) ;
	memcpy(ach,str,str.GetLength());   //  CString转换成char数组 https://blog.csdn.net/qq1012848571/article/details/51594264 

	m_cTextEdit.SetWindowText( ach ); 
	m_cTextEdit.ShowWindow( SW_SHOW ); 
	m_cTextEdit.MoveWindow( &rc ); 
	m_cTextEdit.SetFocus(); 
	m_cTextEdit.CreateSolidCaret( 1, rc.Height() - 5 );
	m_cTextEdit.ShowCaret(); 
	m_cTextEdit.SetSel( -1 ); 
 
 
--   msFlexGrid 实现 直接修改单元格内容       https://www.xuebuyuan.com/1882607.html
 
 
 
  
 
--  如何给 CCheckListBox 增加多列数据  https://bbs.csdn.net/topics/80300495 

设一下风格就可以了


CListCtrl * p = (CListCtrl *)GetDlgItem(IDC_LIST1);

DWORD dwStyle = ::GetWindowLong(p->m_hWnd, GWL_STYLE); 
dwStyle &= ~(LVS_TYPEMASK);
dwStyle &= ~(LVS_EDITLABELS);

 SetWindowLong(p->m_hWnd, GWL_STYLE, dwStyle |LVS_REPORT|LVS_NOLABELWRAP|LVS_SHOWSELALWAYS);


DWORD styles = LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES;
ListView_SetExtendedListViewStyleEx(p->m_hWnd, styles, styles );


关键是调用 ListView_SetExtendedListViewStyle
并且设置 LVS_EX_CHECKBOXES 属性
查一下 msdn 吧
 
  

 
 
 
   
   -- CListBox 如何实现多列？  https://bbs.csdn.net/wap/topics/10182983 
 
 
 billresp_lctl.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_AUTOARRANGE|LVS_REPORT,   
    CRect(3,485,778,670), this, IDLCTL_BILLRESP);
lvcol.fmt = LVCFMT_LEFT;
  
billresp_lctl.InsertColumn(0, _T("列1"));
billresp_lctl.InsertColumn(1, _T("列2："));
    billresp_lctl.InsertColumn(2, _T("列三"));
billresp_lctl.SetColumnWidth(0,80);
billresp_lctl.SetColumnWidth(1,625);
billresp_lctl.SetColumnWidth(2,50);


void CVcommView::addbillresp_lctl(char * data,int position)
{
   int item_count;


      item_count = billresp_lctl.GetItemCount();
  billresp_lctl.InsertItem(item_count,_T("")); 
  billresp_lctl.SetItemText(item_count,position,_T(data)); 
  billresp_lctl.SetHotItem(item_count);
}
   
 
 
 
 
 
	
 
  
  
 
  
  
    
  
  
  
  
  
  
  
  
  
  
  
  
   