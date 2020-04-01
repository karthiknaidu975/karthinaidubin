#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/wait.h>
#include<vector>
using namespace std;
class Event{
    public:
    void eventopen(){
    pid_t p;
    p=fork();
    if(p>0){
        cout<<"sucess"<<endl;
        cout<<getpid()<<endl;
    }
    else if(p<0){
        cout<<"failure"<<"-1 "<<endl;
    }
    } 

   // cout<<"now let do destroy the process if any process is on wait system"<<endl;

  void indoeventclose(){
      pthread_mutex_t myMutex;
      
      int i,n;
      cin>>n;
     // int p[n];
     pid_t p[n];
      for(i=0;i<n;i++){
          p[i]=fork();
      }

      int count=0;

     // cout<<"now they are 3 process in the event"<<endl;

     for(i=0;i<n-1;i++){
         if(p[i]>p[i+1]){
             count++;
             wait(NULL);
         }

         if(count>0){
               pthread_mutex_init(&myMutex,0);
               //print the number process will be waiting
               cout<<count<<endl;

     // cout<<"now we created 3 multiple process"<<endl;
      
      //here it will destroy the process

       pthread_mutex_destroy(&myMutex);
             
         }
         }
        
       }
       //now we bilock the process if they given any signal then process is unblock;

       void openeventblock(){
            pthread_mutex_t myMutex;
            pthread_mutex_init(&myMutex,0);
            pthread_mutex_lock(&myMutex);
            cout<<"enter the if u want to unblokc the process they give the sgnal and then presss y"<<endl;
            string s;
            cin>>s;

            if(s=="y" || "Y"){
                pthread_mutex_unlock(&myMutex);
                cout<<"sucess"<<endl;
                
            }
            else{
                cout<<"failure"<<"-1"<<endl;
            }
           
       }
};
    int main(){
        Event e;
        e.eventopen();
        e.indoeventclose();
        e.openeventblock();
    
    
    
    return 0;
}
