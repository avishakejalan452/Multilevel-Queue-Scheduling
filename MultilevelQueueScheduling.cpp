#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Process{
    int pid;
    int priority;
    int burst_time;
};

vector<Process> processes;
queue<Process> q1,q2,q3;

void execute_RR(int q){
    int time = 0;
    queue<Process> q_temp;
    while(!q1.empty()){
        Process p = q1.front();
        q1.pop();
        int burst = min(p.burst_time,q);
        p.burst_time -= burst;
        time += burst;
        if(p.burst_time == 0){
            cout<<"Process "<<p.pid<<" completed"<<endl;
        } else {
            q_temp.push(p);
        }
    }
    q1 = q_temp;
}

void execute_PS(){
    queue<Process> q_temp;
    while(!q2.empty()){
        Process p = q2.front();
        q2.pop();
        cout<<"Process "<<p.pid<<" completed"<<endl;
    }
}

void execute_FCFS(){
    queue<Process> q_temp;
    while(!q3.empty()){
        Process p = q3.front();
        q3.pop();
        cout<<"Process "<<p.pid<<" completed"<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        Process p;
        cout<<"Enter priority and burst time of process "<<i+1<<": ";
        cin>>p.priority>>p.burst_time;
        p.pid = i+1;
        processes.push_back(p);
    }
    for(auto p:processes){
        if(p.priority>=1 && p.priority<=3){
            q1.push(p);
        } else if(p.priority>=4 && p.priority<=6){
            q2.push(p);
        } else {
            q3.push(p);
        }
    }
    int quantum = 4;
    int time = 0;
    while(!q1.empty() || !q2.empty() || !q3.empty()){
        if(!q1.empty()){
            execute_RR(quantum);
            time += quantum;
        }
        if(!q2.empty()){
            execute_PS();
            time += 10;
        }
        if(!q3.empty()){
            execute_FCFS();
            time += 10;
        }
    }
    return 0;
}
