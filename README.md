# Issues

## clangd lsp complains about bits/std++.h

1. Create `.clangd` for the compile flags

2. Copy stdc++.h to /usr/local/include/bits

```sh
mkdir /usr/local/include/bits
echo '#define _GLIBCXX_HOSTED 1' > /usr/local/include/bits/stdc++.h
curl -sS https://raw.githubusercontent.com/gcc-mirror/gcc/master/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h >> /usr/local/include/bits/stdc++.h
```

3. Manually remove these headers: `<cstdalign>`,`<cuchar>`,`<memory_resources>` in order for clangd to work, and that `tree_policy` may still not be usable

# Compile and run example using gmake

Eg.

```sh
make clean && make P=projecteuler/3.c
make clean P=projecteuler/3.c
```
