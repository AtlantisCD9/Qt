/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSCSSCharsetRule.h"

#include "CSSCharsetRule.h"
#include "KURL.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSCSSCharsetRule);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCSSCharsetRuleTableValues[3] =
{
    { "encoding", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSCharsetRuleEncoding), (intptr_t)setJSCSSCharsetRuleEncoding THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSCharsetRuleConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCSSCharsetRuleTable = { 4, 3, JSCSSCharsetRuleTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCSSCharsetRuleConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCSSCharsetRuleConstructorTable = { 1, 0, JSCSSCharsetRuleConstructorTableValues, 0 };
class JSCSSCharsetRuleConstructor : public DOMConstructorObject {
public:
    JSCSSCharsetRuleConstructor(JSC::ExecState*, JSC::Structure*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSCSSCharsetRuleConstructor::s_info = { "CSSCharsetRuleConstructor", &DOMConstructorObject::s_info, &JSCSSCharsetRuleConstructorTable, 0 };

JSCSSCharsetRuleConstructor::JSCSSCharsetRuleConstructor(ExecState* exec, Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSCSSCharsetRulePrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSCSSCharsetRuleConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSCharsetRuleConstructor, JSDOMWrapper>(exec, &JSCSSCharsetRuleConstructorTable, this, propertyName, slot);
}

bool JSCSSCharsetRuleConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSCharsetRuleConstructor, JSDOMWrapper>(exec, &JSCSSCharsetRuleConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSCSSCharsetRulePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSCSSCharsetRulePrototypeTable = { 1, 0, JSCSSCharsetRulePrototypeTableValues, 0 };
const ClassInfo JSCSSCharsetRulePrototype::s_info = { "CSSCharsetRulePrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSCSSCharsetRulePrototypeTable, 0 };

JSObject* JSCSSCharsetRulePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSCSSCharsetRule>(exec, globalObject);
}

const ClassInfo JSCSSCharsetRule::s_info = { "CSSCharsetRule", &JSCSSRule::s_info, &JSCSSCharsetRuleTable, 0 };

JSCSSCharsetRule::JSCSSCharsetRule(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<CSSCharsetRule> impl)
    : JSCSSRule(structure, globalObject, impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSCSSCharsetRule::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSCSSCharsetRulePrototype(exec->globalData(), globalObject, JSCSSCharsetRulePrototype::createStructure(exec->globalData(), JSCSSRulePrototype::self(exec, globalObject)));
}

bool JSCSSCharsetRule::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSCharsetRule, Base>(exec, &JSCSSCharsetRuleTable, this, propertyName, slot);
}

bool JSCSSCharsetRule::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSCharsetRule, Base>(exec, &JSCSSCharsetRuleTable, this, propertyName, descriptor);
}

JSValue jsCSSCharsetRuleEncoding(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSCharsetRule* castedThis = static_cast<JSCSSCharsetRule*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSCharsetRule* imp = static_cast<CSSCharsetRule*>(castedThis->impl());
    JSValue result = jsStringOrNull(exec, imp->encoding());
    return result;
}


JSValue jsCSSCharsetRuleConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSCharsetRule* domObject = static_cast<JSCSSCharsetRule*>(asObject(slotBase));
    return JSCSSCharsetRule::getConstructor(exec, domObject->globalObject());
}

void JSCSSCharsetRule::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSCSSCharsetRule, Base>(exec, propertyName, value, &JSCSSCharsetRuleTable, this, slot);
}

void setJSCSSCharsetRuleEncoding(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSCSSCharsetRule* castedThis = static_cast<JSCSSCharsetRule*>(thisObject);
    CSSCharsetRule* imp = static_cast<CSSCharsetRule*>(castedThis->impl());
    ExceptionCode ec = 0;
    imp->setEncoding(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}


JSValue JSCSSCharsetRule::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSCSSCharsetRuleConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}
