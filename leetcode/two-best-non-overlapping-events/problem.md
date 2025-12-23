# Problem

https://leetcode.com/problems/two-best-non-overlapping-events

# Tags

#medium #heap #sorting #dp

# Solution

## s1. max heap + sorting

- build a max heap, heap element (event value, event start time)
- sort event by end time
- loop events, for each current event find another event from heap top where start time is later than current event end time
- update the global max value

## s2. sweep line

- make a vector et with size = 2n, elemnt is tuple (time, is_end, value) where time is either start or end.
- sort et by time. if start==end, start is always before end according to is_end flag.
- loop the vector. update max based on is_end flag

## Nice

https://leetcode.com/problems/two-best-non-overlapping-events/solutions/7432227/beats-9923-6-solutions-with-full-explana-dojt/?envType=daily-question&envId=2025-12-23
