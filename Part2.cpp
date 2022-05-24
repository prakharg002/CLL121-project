#include <bits/stdc++.h>
using namespace std;
//steam table data
double p_value[]={700,750,800,850,900,950,1000};
double U_l_value[]={696.33,708.475,720.02,731.065,741.61,751.755,761.5};
double U_v_value[]={2570.9,2573.75,2576,2575.35,2578.5,2580.5,2582};
double V_l_value[]={0.0011,0.0011,0.0011,0.0011,0.0011,0.0011,0.0011};
double V_v_value[]={0.273,0.255,0.24,0.229,0.215,0.204,0.194};
double H_l_value[]={697.1,709.3,720.9,732,742.6,752.8,762.6};
double H_v_value[]={2762,2765,2768,2770,2772,2774,2776};

double U_l(double P)
{ int i;
  double a;
  for(i=1;i<7;i++)
		 {if (P<=p_value[i]) 
            {a = ((P-p_value[i-1])/(p_value[i]-p_value[i-1]))*(U_l_value[i])+((p_value[i]-P)/(p_value[i]-p_value[i-1]))*(U_l_value[i-1]);
             break;
             }
           }

return(a);
}

double U_v(double P)
{ int i;
  double a;
  for(i=1;i<7;i++)
		 {if (P<=p_value[i]) 
            {a = ((P-p_value[i-1])/(p_value[i]-p_value[i-1]))*(U_v_value[i])+((p_value[i]-P)/(p_value[i]-p_value[i-1]))*(U_v_value[i-1]);
             break;
             }
           }

return(a);
}

double V_l(double P)
{ int i;
  double a;
  for(i=1;i<7;i++)
		 {if (P<=p_value[i]) 
            {a = ((P-p_value[i-1])/(p_value[i]-p_value[i-1]))*(V_l_value[i])+((p_value[i]-P)/(p_value[i]-p_value[i-1]))*(V_l_value[i-1]);
             break;
             }
           }

return(a);
}

double V_v(double P)
{ int i;
  double a;
  for(i=1;i<7;i++)
		 {if (P<=p_value[i]) 
            {a = ((P-p_value[i-1])/(p_value[i]-p_value[i-1]))*(V_v_value[i])+((p_value[i]-P)/(p_value[i]-p_value[i-1]))*(V_v_value[i-1]);
             break;
             }
           }

return(a);
}

double H_l(double P)
{ int i;
  double a;
  for(i=1;i<7;i++)
		 {if (P<=p_value[i]) 
            {a = ((P-p_value[i-1])/(p_value[i]-p_value[i-1]))*(H_l_value[i])+((p_value[i]-P)/(p_value[i]-p_value[i-1]))*(H_l_value[i-1]);
             break;
             }
           }

return(a);
}

double H_v(double P)
{ int i;
  double a;
  for(i=1;i<7;i++)
		 {if (P<=p_value[i]) 
            {a = ((P-p_value[i-1])/(p_value[i]-p_value[i-1]))*(H_v_value[i])+((p_value[i]-P)/(p_value[i]-p_value[i-1]))*(H_v_value[i-1]);
             break;
             }
      
           }

return(a);
}


double g_1(double P,double alpha)
{ double a;
   a = alpha/V_l(P)+ (1- alpha)/V_v(P);

return(a);
}

double g_2(double P,double alpha)
{ double a;
   a = alpha*U_l(P)/V_l(P)+ (1- alpha)*U_v(P)/V_v(P);

return(a);


}
double f(double P_f, double alpha_f,double P_i, double alpha_i,double b,double a)
{double x;
  x = ((g_2(P_f,alpha_f)-g_2(P_i,alpha_i))/(g_1(P_f,alpha_f)-g_1(P_i,alpha_i)))-b/a;



return(x);
}


int main()

{ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 #ifndef ONLINE JUDGE
    freopen("part_2_input.txt" ,"r",stdin);
    freopen("part_2_output.txt" ,"w",stdout);
    #endif 
  int p; 
 double P_1,P_2,mdot_1,mdot_2,del_t,P_i,alpha_i;
cin>>P_1;
cin>>P_2;
cin>>mdot_1;
cin>>mdot_2;
cin>>del_t;
cin>>P_i;
cin>>alpha_i;


double a = (mdot_1-mdot_2)*del_t;
double b = ((mdot_1*H_v(P_1)*del_t)-(mdot_2*H_v(P_2)*del_t));

 
double alpha_f_opt=(a*g_2(P_i,alpha_i)-b*g_1(P_i,alpha_i)-((a*U_v(P_1-50)-b)/V_v(P_1-50)))/(((a*U_l(P_1-50)-b)/V_l(P_1-50))-((a*U_v(P_1-50)-b)/V_v(P_1-50)));
double V_acc= a/(g_1(P_1-50,alpha_f_opt)-g_1(P_i,alpha_i));
if (alpha_f_opt<=0.95)
  { cout<<alpha_f_opt<<"\n";
   cout<<V_acc<<"\n";
   }
else
{
 cout<<"value of alpha f for this case exceeds 0.95 \n";
} 


 return (0);
}
