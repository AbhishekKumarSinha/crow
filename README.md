# crow
Creating ReST Framework Example using Crow.

## Environment Setup
Below envivornment needs to be set to test this project on Ubuntu 20.04 LTS.

Required components are :
- build-essential
  - g++
- boost
- curl
- crow_all.h      _-->This is included in the inc folder of this project._


```bash
sudo apt install build-essential libboost-all-dev
sudo apt install curl
```

## Compilation

To complie the program GNU C++ compiler g++ can be used as shown below in terminal.

```bash
g++ -g -Wall  *.cpp -I./inc  -lpthread -lboost_system -std=c++17
```
To run the program in Linux system like Ubuntu execute as shown below.

```bash
./a.out
```

## Testing using cURL
Below mentioned ReST API can be tested.

GET
```bash
curl -H "Content-Type: application/json" -X GET http://localhost:18080
```

POST /signup
```bash
curl -H "Content-Type: application/json" -X POST -d '{"username":"abhishek","password":"sinha"}' http://localhost:18080/signup
```

POST /login
```bash
curl -v -H "Content-Type: application/json" -X POST -d '{"username":"abhishek","password":"sinha"}' http://localhost:18080/login
```

Upcoming API

## License
[MIT](https://choosealicense.com/licenses/mit/)

<!-- CONTACT -->
## Contact

Abhishek Kumar Sinha - [@_abhisheksinha](https://twitter.com/_abhisheksinha) - email4abhi@gmail.com

Project Link: [https://github.com/AbhishekKumarSinha/cpp](https://github.com/yAbhishekKumarSinha/crow)
