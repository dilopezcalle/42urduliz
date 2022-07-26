#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;	
    milliseconds += tp.tv_usec / 1000;
    return (milliseconds);
}

long ft_timer_comp(struct timeval timer)
{
    struct timeval	tp;
	long			result;

	gettimeofday(&tp, NULL);
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	result -= (timer.tv_sec * 1000) + (timer.tv_usec / 1000);
	return (result);
}


void	ft_usleep(long milisecons)
{
	struct timeval timer;

	gettimeofday(&timer, NULL);
	while (milisecons > ft_timer_comp(timer))
	{
		usleep(500);
	}
}

int main(void)
{
    long start_time;
		
    start_time = get_time();

    while (1)
    {
        printf("%ld\n", get_time() - start_time);
    	ft_usleep(200);
    }
}