/*
    Copyright 2016 Raphael Medaer <rme@escaux.com>

    This file is part of proxygen-routing (libproxygenrouting).

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef ROUTE_HPP
#define ROUTE_HPP

#include "AbstractRoute.h"

using namespace std;

namespace proxygen {
namespace routing {

template<typename T>
class Route : public AbstractRoute
{
public:
    Route(HTTPMethod method, std::string path) :
        AbstractRoute(method, path)
    {
    }

    virtual RequestHandler *handler(
        Router *router,
        HTTPMessage* message,
        ParameterSet params) const
    {
        return new T(router, message, params);
    }
};

}
}

#endif // ROUTE_HPP
