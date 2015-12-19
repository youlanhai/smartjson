//
//  node.hpp
//  minijson
//
//  Created by youlanhai on 15/12/19.
//  Copyright © 2015年 youlanhai. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include "types.hpp"
#include "config.hpp"

#if JSON_SUPPORT_STL_STRING
#include <string>
#endif

namespace mjson
{
    class Object;
    class String;
    class Dict;
    class Array;
    class IAllocator;
    
    class Node
    {
    public:
        
        Node();
        Node(bool value);
        Node(Integer value);
        Node(Float value);
        Node(Object *p);
        Node(const char *str, IAllocator *allocator);
        Node(const Node &other);
        ~Node();
        
        bool isNull() const;
        bool isBool() const;
        bool isInt() const;
        bool isFloat() const;
        bool isString() const;
        bool isArray() const;
        bool isDict() const;
        bool isPointer() const;
        
        bool        asBool()    const;
        Integer     asInteger() const;
        Float       asFloat()   const;
        String*     asString()  const;
        const char* asCString() const;
        Array*      asArray()   const;
        Dict*       asDict()    const;
        
        void setNull();
        void setBool(bool value);
        void setInteger(Integer value);
        void setFloat(Float value);
        void setString(const char *str, IAllocator *allocator = 0);
        void setString(const char *str, size_t length, IAllocator *allocator = 0);
        void setArray();
        void setDict();
        
        const Node& operator = (bool value);
        const Node& operator = (Integer value);
        const Node& operator = (Float value);
        const Node& operator = (const char *value);
        const Node& operator = (const Object *value);
        const Node& operator = (const Node &value);
        
        bool operator == (const Node &value);
        
        size_t size() const;
        Node clone() const;
        
        Node& operator[] (SizeType index);
        Node& operator[] (const char *key);
        
        
#if JSON_SUPPORT_STL_STRING
        Node(const std::string &value, IAllocator *allocator = 0);
        const Node& operator = (const std::string &value);
        Node& operator[] (const std::string &key);
        
        void setStdString(const std::string &value, IAllocator *allocator = 0);
        void asStdString(std::string &out) const;
        std::string asStdString() const;
#endif
        
    private:
        struct Value
        {
            union
            {
                bool        b;
                Integer     i;
                Float       f;
                Object*     p;
            };
        };
        
        Value       value_;
        int         type_;
    };
    
    
    struct NodePair
    {
        String*     key;
        Node        value;
    };
}

#endif /* node_hpp */