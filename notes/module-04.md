Signals - software interrupts

signal function
` void (*signal(int signo, void (*func)(int)))(int);`
` Returns: previous disposition of signal if OK, SIG_ERR on error`