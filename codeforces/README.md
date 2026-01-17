# Compiler

https://codeforces.com/blog/entry/121114

```sh
gcc -std=c11 -static -DONLINE_JUDGE -fno-asm -lm -s -Wl,--stack=268435456 -O2 %1
g++ -static -DONLINE_JUDGE -Wl,--stack=268435456 -O2 -std=c++17 %1
```

# API

- https://codeforces.com/apiHelp
- [Python API wrapper](https://github.com/VadVergasov/CodeforcesApiPy)

# Generate template

```bash
source .venv/bin/activate.fish
make template c=CONTEST p=PROBLEM
# or
python util.py template -c CONTEST -p PROBLEM
deactivate
```
