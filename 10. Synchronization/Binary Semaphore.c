struct binary_semaphore {
    enum {zero, one} value;
    queue_type queue;
};
void semWaitB (binary_semaphore s)
{
    if (s.value == one)
        s.value = zero;
    else {
        add this process to s.queue;
        block this process;
    }

}
void semSignalB(semaphore s)
{
    if (s.queue is empty)
        s.value = one;
    else {
        remove a process P from s.queue;
        wakeup process P;
    }
    
}