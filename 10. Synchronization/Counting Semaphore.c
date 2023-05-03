struuct semaphore {
    int count;
    queue_type queue;
};
void semWait(semaphore s)
{
    s.count--;
    if (s.count < 0) {
        place this process is s.queue;
        block this process;
    }

}
void semSignal(semaphore s)
{
    s.count++;
    if (s.count <= 0) {
        remove a process P from s.queue;
        wakeup process P;
    }
}