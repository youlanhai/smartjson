//
//  node.hpp
//  smartjson
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
        Node(short value);
        Node(int value);
        Node(int64_t value);
        Node(float value);
        Node(double value);
        Node(Object *p);
        Node(const char *str, size_t size = 0, IAllocator *allocator = nullptr);
        Node(const Node &other);
        ~Node();
        
        bool isNull() const;
        bool isBool() const;
        bool isInt() const;
        bool isFloat() const;
        bool isString() const;
        bool isArray() const;
        bool isDict() const;
        bool isNumber() const;
        bool isPointer() const;
        
        bool        asBool()    const;
        Integer     asInteger() const;
        Float       asFloat()   const;
        String*     asString()  const;
        const char* asCString() const;
        Array*      asArray()   const;
        Dict*       asDict()    const;
        
        String* rawString() const;
        Array*  rawArray() const;
        Dict*   rawDict() const;
        
        void setNull();
        void setString(const char *str, size_t size = 0, IAllocator *allocator = 0);
        void setArray(IAllocator *allocator = 0);
        void setDict(IAllocator *allocator = 0);
        
        const Node& operator = (bool value);
        const Node& operator = (short value);
        const Node& operator = (int value);
        const Node& operator = (int64_t value);
        const Node& operator = (float value);
        const Node& operator = (double value);
        const Node& operator = (const char *value);
        const Node& operator = (const Object *value);
        const Node& operator = (const Node &value);
        
        bool operator == (const Node &value) const;
        bool operator != (const Node &value) const;
        
        size_t size() const;
        Node clone() const;
        Node deepClone() const;
        
        Node& operator[] (SizeType index);
        Node& operator[] (const char *key);
        
        const Node& operator[] (SizeType index) const;
        const Node& operator[] (const char *key) const;
        
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
        Node        key;
        Node        value;
    };
}

#if JSON_CODE_INLINE
#include "node.ipp"
#endif

#endif /* node_hpp */
