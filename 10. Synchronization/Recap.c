semWait(s)
{
    while (compare_and_swqp(s.flag, 0, 1) == 1)
    // do notiong
    s.count--;
    if(s.count < 0){
        // place this process in s.queue;
        // block this process (must also set s.flag to 0);
    }
    s.flag = 0;

}

semSignal(s)
{
    while (compare_and_swap(s.flag, 0, 1) == 1)
    // do nothing
    s.count++;
    if(s.count <= 0){
        // remove a process P from s.queue;
        // wakeup process P;
    }
    s.flag = 0;
}

semWait(s)
{
    inhibit interrupts;
    s.count--;
    if(s.count<0){
        // place this process in s.queue;
        // block this process and allow interrupts;
    }
    else 
        allow interrupts;
        s.count++;
        if (s.count<=0){
            // remove a process P from s.queue;
            // place process P on ready list;
        }
        allow interrupts;



}