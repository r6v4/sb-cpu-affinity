/* Copyright (c) 2008 Nikodemus Siivola <nikodemus@random-state.net>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or esell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE. */

#define _GNU_SOURCE
#include <sched.h>

int cpu_setsize = CPU_SETSIZE;
int cpu_mask_size = sizeof(cpu_set_t);

int get_cpu_affinity_mask(cpu_set_t *mask)
{
    return sched_getaffinity(0, CPU_SETSIZE, mask);
}

int set_cpu_affinity_mask(cpu_set_t *mask)
{
    return sched_setaffinity(0, CPU_SETSIZE, mask);
}

void zero_cpu_affinity_mask(cpu_set_t *mask)
{
    CPU_ZERO(mask);
}

void set_cpu_affinity(int cpu, cpu_set_t *mask)
{
    CPU_SET(cpu, mask);
}

int cpu_affinity_p(int cpu, cpu_set_t *mask)
{
    return CPU_ISSET(cpu, mask);
}

void clear_cpu_affinity(int cpu, cpu_set_t *mask)
{
    CPU_CLR(cpu, mask);
}

    
    
