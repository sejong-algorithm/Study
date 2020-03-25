## DNS  &  WAS

### DNS(Domain Name Service)

* TCP/IP 네트워크 상에서 사람이 기억하기 쉽게 문자로 만들어진 도메인을 컴퓨터가 처리할 수 있는 숫자로 된 인터넷주소(IP)로 바꾸는 시스템인 Domain Name System을 일컫거나, 이러한 역할을 하는 Domain Name Server을 일컫기도 함
* 도메인이름은 사람들이 기억하기 쉽고 의미가 있는 인터넷 주소이지만 실제로 인터넷에서 특정 컴퓨터를 찾기 위해서는 숫자체계 즉 IP주소가 필요하다. 
  * ex) www.naver.com -> 125.209.222.141 
* 이렇듯 도메인에 대한 이름풀이를 해주는것이 DNS의 역할
* 기본 동작 과정 (Recursive Query)
  * ex) www.naver.com 
  * ![image-20200323144000788](C:\Users\Hyeok\AppData\Roaming\Typora\typora-user-images\image-20200323144000788.png)

###  WAS 와 Web Server

* Web Server

  * 웹 브라우저와 같은 클라이언트로 부터 Http 요청을 받아들이고, html문서와 같은 웹 페이지를 정적으로 처리해 반환한다.
  * Web Server가 필요한 이유?
    * 클라이언트(웹 브라우저)에 이미지 파일(정적 컨텐츠)을 보내는 과정을 생각해보자.
      이미지 파일과 같은 정적인 파일들은 웹 문서(HTML 문서)가 클라이언트로 보내질 때 함께 가는 것이 아니다.
    * 클라이언트는 HTML 문서를 먼저 받고 그에 맞게 필요한 이미지 파일들을 다시 서버로 요청하면 그때서야 이미지 파일을 받아온다.
    * Web Server를 통해 정적인 파일들을 Application Server까지 가지 않고 앞단에서 빠르게 보내줄 수 있다.
    * -> Web server에서는 정적 컨텐츠만 처리하도록 기능을 분배하여 서버의 부담을 줄일수 있다.
  * 종류
    * 아파치
    * 인터넷 정보 서버(IIS)
    * 엔터프라이즈 서버

* WAS

  * **웹 애플리케이션 서버**(Web Application Server, 약자 **WAS**)는 [웹 애플리케이션](https://ko.wikipedia.org/wiki/웹_애플리케이션)과 [서버](https://ko.wikipedia.org/wiki/서버) 환경을 만들어 동작시키는 기능을 제공하는 [소프트웨어 프레임워크](https://ko.wikipedia.org/wiki/소프트웨어_프레임워크)(미들웨어)이다.

  * 주로 데이터 베이스 서버와 같이 서비스를 수행

  * 동적 컨텐츠를 제공

  * WAS가 필요한 이유?

    * 웹 페이지는 정적 컨텐츠와 동적 컨텐츠가 모두 존재한다.
      사용자의 요청에 맞게 적절한 동적 컨텐츠를 만들어서 제공해야 한다.

    * 이때, Web Server만을 이용한다면 사용자가 원하는 요청에 대한 결과값을 모두 미리 만들어 놓고 서비스를 해야 한다.
    * 하지만 이렇게 수행하기에는 자원이 절대적으로 부족하다.
    * 따라서 WAS를 통해 요청에 맞는 데이터를 DB에서 가져와서 비즈니스 로직에 맞게 그때 그때 결과를 만들어서 제공함으로써 자원을 효율적으로 사용할 수 있다.

  * 종류

    * Tomcat
    * JBoss
    * Jeus
    * Web Sphere 

* **자원 이용의 효율성 및 장애 극복, 배포 및 유지보수의 편의성을 위해 Web Server와 WAS를 분리한다.**

* ![image-20200323164309871](C:\Users\Hyeok\AppData\Roaming\Typora\typora-user-images\image-20200323164309871.png)

