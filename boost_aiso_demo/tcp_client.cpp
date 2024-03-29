/*
 * @Author: XiangyDeng 158812420@qq.com
 * @Date: 2023-04-25 10:12:15
 * @LastEditors: XiangyDeng 158812420@qq.com
 * @LastEditTime: 2023-11-04 15:00:26
 * @FilePath: /CI_test/tcp_client.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//code of client
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    try
    {
        //(1)通过tcp::socket类定义一个tcp client对象socket
        boost::asio::io_service io;
        tcp::socket socket(io);

        //(2)通过connect函数连接服务器，打开socket连接。
        tcp::endpoint end_point(boost::asio::ip::address::from_string("127.0.0.1"), 1000);
        socket.connect(end_point);

        for (;;)
        {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            //(3)通过read_some函数来读数据
            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
            {
                break;    //connection closed cleadly by peer
            }
            else if (error)
            {
                throw boost::system::system_error(error);    //some other error
            }
            cout << "test: " << buf.data() << endl;
            break;
        }
    }
    catch (std::exception& e)
    {
        cout << "failed!" << endl;

        cout << "failed!" << endl;

        cout << "failed!" << endl;

        cout << "failed!" << endl;

        cout << "failed!" << endl;


        cout<<e.what()<<endl;
    }
}