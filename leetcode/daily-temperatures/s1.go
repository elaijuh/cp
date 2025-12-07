func dailyTemperatures(temperatures []int) []int {
	ans := make([]int, len(temperatures))
	st := arraystack.New()
	for i, v := range temperatures {
		for !st.Empty() {
			top, _ := st.Peek()
			t, _ := top.(int)
			if temperatures[t] < v {
				ans[t] = i - t
				st.Pop()
				continue
			}
			break
		}
		st.Push(i)
	}
	return ans
}
