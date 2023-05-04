
const int sizeofbuffer = /*buffer size*/;
semaphore s = 1, n = 0, e = sizeofbuffer;
void producer(){
    while (true){
        produce();
        semWait(e);
        semWait(s);
        append();
        semSignal(s);
        semSignal(n);
    }
}
void consumer()
{
    while(true){
        semWait(n);
        semWait(s);
        take();
        semSignal(s);
        semSignal(e);
        consume();
    }
}
void main()
{
    parbegin(producer, consumer);
}
