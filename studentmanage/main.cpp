#include "student.h"


using namespace std;



int menu()
{
  fflush(stdout);
  int choice;
  system("cls");
  cout<<"��ҳ"<<endl;
  cout<<"**********************************************************************************"<<endl;
  cout<<"*��������������������  ��   ѧ �� �� Ϣ �� �� ϵ  ͳ     ��  ��������������������*"<<endl;
  cout<<"*��������������������         ��������         �������������������*"<<endl;
  cout<<"*��������������������  ��         1.����ѧ����Ϣ         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         2.��ӡѧ����Ϣ         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         3.��ѯѧ����Ϣ         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         4.����ѧ���ɼ�         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         5.ɾ��ѧ����Ϣ         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         6.�޸�ѧ����Ϣ         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         7.����ͳ�Ƴɼ�         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         8.��������ļ�         ��  �������������������*"<<endl;
  cout<<"*��������������������  ��         0.��ȫ�˳�ϵͳ         ��  �������������������*"<<endl;
  cout<<"**********************************************************************************"<<endl;
  cout<<"\t\t\n\t\t���������ѡ��";


  fflush(stdin);

  cin>>choice;
  return choice;
}
int main()
{
//    char s1[]="��־ǿ",s2[]="槼�";
//       while(1)
//       {
//           printf("%s\t%d\t%d\n",s1,150,10);
//           printf("%s\t%d\t%d\n",s2,10,120);
//           getchar();
//       }
       char ch;
       char s[100000];
       int num;
       cout<<"���ڼ������ݣ����Եȡ�������\n";
       datadownload();
       sort(lis.begin(),lis.end(),cmpa);
       Sleep(1000);
       cout<<"����ɹ�����"<<endl;
       Sleep(500);
       again:
        switch(menu())
      {
        case 0:system("cls");cout<<"\n\n****************���˳�ϵͳ****************"<<endl;break;
        case 1:
               system("cls");
               cout<<"��ҳ->����ѧ����Ϣ"<<endl;
               cout<<"1.�ֶ����� 2.�ļ�����"<<endl;
               cin>>num;
               if(num==1)
               {
                 cout<<"������ѧ������"<<endl;
                 cin>>num;
                 while(num--) push();
                 sort(lis.begin(),lis.end(),cmpa);
                 file_renew();
                 cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
               }
               else if(num==2)
               {
                    file_push();
                    sort(lis.begin(),lis.end(),cmpa);
                    file_renew();
                    cout<<"\t\t[��Ϣ��¼�롭��]\n\n";
                     cout<<"����������ء�������\n";
                 getchar();
                  goto again;
               }


                 break;



        case 2:
            system("cls");
            cout<<"��ҳ->��ӡѧ����Ϣ"<<endl;
            out();
            cout<<"����������ء�������\n";
            getchar();
            getchar();
            goto again;
            break;
        case 3:
            system("cls");
            cout<<"��ҳ->��ѯѧ����Ϣ"<<endl;
            cout<<"1.ģ����ѯ(����) 2.��ȷ��ѯ(����) 3.ѧ�Ų�ѯ"<<endl;
            cin>>num;
            if(num==1)
                query_name_vague();
            else if(num==2)
                query_name_accurate();
            else if(num==3)
                query_number();
            cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 4:
            system("cls");
            cout<<"��ҳ->����ѧ����Ϣ"<<endl;
            ins();

             cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 5:
            system("cls");
            cout<<"��ҳ->ɾ��ѧ����Ϣ"<<endl;
            del();

             cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 6:
            system("cls");
            cout<<"��ҳ->�޸�ѧ����Ϣ"<<endl;
            modify();
            cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 7:
            system("cls");
            cout<<"��ҳ->����ͳ�Ƴɼ�"<<endl;
            cout<<"1.���� 2.ͳ��"<<endl;
            cin>>num;
            if(num==1)
            {
                int c;
                cout<<"1.�������� 2.���ƽ��� 3.�ܳɼ����� 4.�ܳɼ�����"<<endl;
                cin>>c;
                if(c==1)single_score_ascend();
                else if(c==2)single_score_descend();
                else if(c==3)all_score_ascend();
                else if(c==4)all_score_descend();
            }
            else if(num==2)
            {
                int c;
                cout<<"1.ѧ��ƽ���ֺ��ܷ� 2.��Ŀ��߷֣���ͷ֣�ƽ����"<<endl;
                cin>>c;
                if(c==1)stud_count();
                else if(c==2) subject_count();
            }
             cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        case 8:
            system("cls");
            file_renew();
            cout<<"\n\n\t\t[out.txt�Ѹ��³ɹ�������]\n";
            cout<<"����������ء�������\n";
                 getchar();
                 getchar();
                 goto again;
                 break;
        default:goto again;
      }


   return 0;
}
