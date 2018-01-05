#include "student.h"


using namespace std;



int menu()
{
  fflush(stdout);
  int choice;
  system("cls");
  cout<<"首页"<<endl;
  cout<<"**********************************************************************************"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓〓  ☆   学 生 信 息 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         1.输入学生信息         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         2.打印学生信息         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         3.查询学生信息         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         4.插入学生成绩         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         5.删除学生信息         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         6.修改学生信息         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         7.排序统计成绩         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         8.更新输出文件         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"*〓〓〓〓〓〓〓〓〓★  ☆         0.安全退出系统         ☆  ★〓〓〓〓〓〓〓〓〓*"<<endl;
  cout<<"**********************************************************************************"<<endl;
  cout<<"\t\t\n\t\t请输入你的选择：";


  fflush(stdin);

  cin>>choice;
  return choice;
}
int main()
{
//    char s1[]="杨志强",s2[]="妲己";
//       while(1)
//       {
//           printf("%s\t%d\t%d\n",s1,150,10);
//           printf("%s\t%d\t%d\n",s2,10,120);
//           getchar();
//       }
       char ch;
       char s[100000];
       int num;
       cout<<"正在加载数据，请稍等…………\n";
       datadownload();
       sort(lis.begin(),lis.end(),cmpa);
       Sleep(1000);
       cout<<"载入成功……"<<endl;
       Sleep(500);
       again:
        switch(menu())
      {
        case 0:system("cls");cout<<"\n\n****************已退出系统****************"<<endl;break;
        case 1:
               system("cls");
               cout<<"首页->输入学生信息"<<endl;
               cout<<"1.手动输入 2.文件输入"<<endl;
               cin>>num;
               if(num==1)
               {
                 cout<<"请输入学生个数"<<endl;
                 cin>>num;
                 while(num--) push();
                 sort(lis.begin(),lis.end(),cmpa);
                 file_renew();
                 cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
               }
               else if(num==2)
               {
                    file_push();
                    sort(lis.begin(),lis.end(),cmpa);
                    file_renew();
                    cout<<"\t\t[信息已录入……]\n\n";
                     cout<<"按任意键返回…………\n";
                 getchar();
                  goto again;
               }


                 break;



        case 2:
            system("cls");
            cout<<"首页->打印学生信息"<<endl;
            out();
            cout<<"按任意键返回…………\n";
            getchar();
            getchar();
            goto again;
            break;
        case 3:
            system("cls");
            cout<<"首页->查询学生信息"<<endl;
            cout<<"1.模糊查询(姓名) 2.精确查询(姓名) 3.学号查询"<<endl;
            cin>>num;
            if(num==1)
                query_name_vague();
            else if(num==2)
                query_name_accurate();
            else if(num==3)
                query_number();
            cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 4:
            system("cls");
            cout<<"首页->插入学生信息"<<endl;
            ins();

             cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 5:
            system("cls");
            cout<<"首页->删除学生信息"<<endl;
            del();

             cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 6:
            system("cls");
            cout<<"首页->修改学生信息"<<endl;
            modify();
            cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 7:
            system("cls");
            cout<<"首页->排序统计成绩"<<endl;
            cout<<"1.排序 2.统计"<<endl;
            cin>>num;
            if(num==1)
            {
                int c;
                cout<<"1.单科升序 2.单科降序 3.总成绩升序 4.总成绩降序"<<endl;
                cin>>c;
                if(c==1)single_score_ascend();
                else if(c==2)single_score_descend();
                else if(c==3)all_score_ascend();
                else if(c==4)all_score_descend();
            }
            else if(num==2)
            {
                int c;
                cout<<"1.学生平均分和总分 2.科目最高分，最低分，平均分"<<endl;
                cin>>c;
                if(c==1)stud_count();
                else if(c==2) subject_count();
            }
             cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 8:
            system("cls");
            file_renew();
            cout<<"\n\n\t\t[out.txt已更新成功！……]\n";
            cout<<"按任意键返回…………\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        default:goto again;
      }


   return 0;
}
