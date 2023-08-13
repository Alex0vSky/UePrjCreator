// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ENGINE_Subsystem_generated_h
#error "Subsystem.generated.h already included, missing '#pragma once' in Subsystem.h"
#endif
#define ENGINE_Subsystem_generated_h

#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_SPARSE_DATA
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSubsystem(); \
	friend struct Z_Construct_UClass_USubsystem_Statics; \
public: \
	DECLARE_CLASS(USubsystem, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(USubsystem)


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_INCLASS \
private: \
	static void StaticRegisterNativesUSubsystem(); \
	friend struct Z_Construct_UClass_USubsystem_Statics; \
public: \
	DECLARE_CLASS(USubsystem, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(USubsystem)


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USubsystem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USubsystem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USubsystem(USubsystem&&); \
	NO_API USubsystem(const USubsystem&); \
public:


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USubsystem(USubsystem&&); \
	NO_API USubsystem(const USubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USubsystem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USubsystem)


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_46_PROLOG
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_SPARSE_DATA \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_INCLASS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_SPARSE_DATA \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ENGINE_API UClass* StaticClass<class USubsystem>();

#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_SPARSE_DATA
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_RPC_WRAPPERS
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_RPC_WRAPPERS_NO_PURE_DECLS
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDynamicSubsystem(); \
	friend struct Z_Construct_UClass_UDynamicSubsystem_Statics; \
public: \
	DECLARE_CLASS(UDynamicSubsystem, USubsystem, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UDynamicSubsystem)


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_INCLASS \
private: \
	static void StaticRegisterNativesUDynamicSubsystem(); \
	friend struct Z_Construct_UClass_UDynamicSubsystem_Statics; \
public: \
	DECLARE_CLASS(UDynamicSubsystem, USubsystem, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Engine"), NO_API) \
	DECLARE_SERIALIZER(UDynamicSubsystem)


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDynamicSubsystem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDynamicSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDynamicSubsystem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDynamicSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDynamicSubsystem(UDynamicSubsystem&&); \
	NO_API UDynamicSubsystem(const UDynamicSubsystem&); \
public:


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDynamicSubsystem(UDynamicSubsystem&&); \
	NO_API UDynamicSubsystem(const UDynamicSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDynamicSubsystem); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDynamicSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDynamicSubsystem)


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_PRIVATE_PROPERTY_OFFSET
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_86_PROLOG
#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_SPARSE_DATA \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_RPC_WRAPPERS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_INCLASS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_PRIVATE_PROPERTY_OFFSET \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_SPARSE_DATA \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_INCLASS_NO_PURE_DECLS \
	Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h_89_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ENGINE_API UClass* StaticClass<class UDynamicSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Source_Runtime_Engine_Public_Subsystems_Subsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
