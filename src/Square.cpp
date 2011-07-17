
#include <iostream>
#include "Square.hpp"

Square::Square() : _mut(), _data(0) {
    
}

Square::~Square()
{
    
}

int32_t Square::getRawData() const
{
    boost::lock_guard<boost::mutex> lock(_mut);
    return (_data);
}

void Square::setRawData(int32_t mask)
{
    _mut.lock();
    _data = mask;
    _mut.unlock();
}

void Square::dumpData() const
{
    boost::lock_guard<boost::mutex> lock(_mut);
    const Square::Data & data = this->getData();
    std::cout << "Bit field dump" << std::endl;
    std::cout << "player : " << data.player << std::endl;
    std::cout << "is takable : " << data.is_takable << std::endl;
    std::cout << "diagl : " << data.diagl << std::endl;
    std::cout << "diagr : " << data.diagr << std::endl;
    std::cout << "horz : " << data.horz << std::endl;
    std::cout << "vert : " << data.vert << std::endl;
    std::cout << "value : " << this->getRawData()<< std::endl;
    std::cout << "value hex : 0x" << std::hex;
    std::cout << this->getRawData() << std::endl;
    std::cout << "[.....]" << std::endl;
    std::cout << "Raw Data Bit Mask dump" << std::endl;
    std::cout << "player : " << GET_PLAYER(_data) << std::endl;
    std::cout << "is takable : " <<  GET_TAKABLE(_data) << std::endl;
    std::cout << "diagl : " << GET_DIAGL(_data) << std::endl;
    std::cout << "diagr : " << GET_DIAGR(_data) << std::endl;
    std::cout << "horz : " << GET_HORZ(_data) << std::endl;
    std::cout << "vert : " << GET_VERT(_data) << std::endl;
    std::cout << "value : " << std::dec << this->getRawData()<< std::endl;
    std::cout << "value hex : 0x" << std::hex;
    std::cout << this->getRawData() << std::endl;
}


