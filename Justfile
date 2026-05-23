
run-modulo:
    #!/usr/bin/env bash
    cd Examples
    gcc Modulo.cpp -std=c++20 -lstdc++ -o Modulo
    ./Modulo

build-tests:
    #!/usr/bin/env bash
    cd Tests && make all

run-tests:
    #!/usr/bin/env bash
    cd Tests && make all && ../bin/tests -s -r compact

clean-tests:
    #!/usr/bin/env bash
    cd Tests && make clean
