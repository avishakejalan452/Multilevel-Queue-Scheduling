# MULTILEVEL-QUEUE-SCHEDULING

METHODOLOGY:

The multilevel queue scheduling algorithm involves creating multiple queues and assigning different priorities to them. Each queue is assigned a specific range of priorities. Processes are then assigned to their respective queues according to their priority. The highest priority queue is assigned a Round Robin algorithm with a quantum time of 4, the medium priority queue is assigned a priority scheduling algorithm, and the lowest priority queue is assigned a First Come First Serve algorithm. CPU keeps shifting between the queues after every 10 seconds. The program will take input from the user regarding the number of processes, their priority, and burst time. The output will contain a report showing the processes' scheduling sequence and the waiting time of each process
