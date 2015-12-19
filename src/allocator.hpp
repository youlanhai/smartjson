//
//  allocator.hpp
//  minijson
//
//  Created by youlanhai on 15/12/19.
//  Copyright © 2015年 youlanhai. All rights reserved.
//

#ifndef allocator_hpp
#define allocator_hpp

#include "reference.hpp"

namespace mjson
{
    
    class IAllocator : public Reference
    {
    public:
        IAllocator();
        ~IAllocator();
        
        virtual void*   malloc(size_t size) = 0;
        virtual void*   realloc(void *p, size_t newSize) = 0;
        virtual void    free(void *p) = 0;
        
        virtual String* createString() = 0;
        virtual Array*  createArray() = 0;
        virtual Dict*   createDict() = 0;
        
        virtual void    freeObject(Object *p) = 0;
    };
    
    class RawAllocator : public IAllocator
    {
    public:
        RawAllocator();
        ~RawAllocator();
        
        virtual void*   malloc(size_t size);
        virtual void*   realloc(void *p, size_t newSize);
        virtual void    free(void *p);
        
        virtual String* createString();
        virtual Array*  createArray();
        virtual Dict*   createDict();
        
        virtual void    freeObject(Object *p);
    };
}


#endif /* allocator_hpp */
