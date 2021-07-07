
环境：linux
依赖：apr、apr-util
apr、apr-util下载地址：http://apr.apache.org/download.cgi
log4cxx下载地址：http://logging.apache.org/log4cxx/download.html
 
依赖项 yum install expat-devel

安装步骤：
1.由于log4cxx是依赖于apr的，因此先安装apr和apr-util这两个库,我会将这两个库安装到同一个目录下；
下载完之后，当前目录有apr-1.4.6.tar.gz和apr-util-1.5.1.tar.gz两个文件。
[plain] view plaincopyprint?
 

    $>tar xvf apr-1.4.6.tar.gz  
    $>cd apr-1.4.6  
    $>./configuer --prefix=/usr/local/apr  
    $>make  
    $>make install  



目前apr安装完成，会在/usr/local下产生apr目录
[plain] view plaincopyprint?
 

    $>tar xvf apr-util-1.5.1.tar.gz  
    $>cd apr-util-1.5.1  
    $>./configure  --prefix=/usr/local/apr --with-apr=/usr/local/apr  
    $>make  
    $>make install  



apr-util也会安装/usr/local/apr目录下
 
2.开始安装log4cxx，下载完之后，当前目录下有apache-log4cxx-0.10.0.tar.gz。
[plain] view plaincopyprint?
 

    $>tar xvf apache-log4cxx-0.10.0.tar.gz  
    $>cd apache-log4cxx-0.10.0  
    $>./configure --prefix=/usr/local/log4cxx --with-apr=/usr/local/apr --with-apr-util=/usr/local/apr  --with-charset=utf-8 --with-logchar=utf-8  
    $>make  



注意：由于我用的是ubuntu系统，默认编码是utf-8，因此必须要加上 --with-charset=utf-8 --with-logchar=utf-8，不然中文输出是一堆乱码。