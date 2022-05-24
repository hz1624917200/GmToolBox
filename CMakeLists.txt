cmake_minimum_required(VERSION 3.0)
project(GmSSL)

#set(CMAKE_MACOSX_RPATH 1)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mrdrnd -mrdseed")

include_directories(include)

add_library(
	gmssl
#	SHARED
	src/aes.c
	src/aes_modes.c
	src/block_cipher.c
	src/gcm.c
	src/gf128.c
	src/rand.c
    src/hex.c
    src/padding.c
#	src/rdrand.c
	src/sm3.c
	src/sm4_common.c
	src/sm4_enc.c
	src/sm4_modes.c
	src/sm4_setkey.c
)
target_link_libraries(gmssl dl)
SET_TARGET_PROPERTIES(gmssl PROPERTIES VERSION 3.0 SOVERSION 3)


# tools

# add_executable(
# 	gmssl-bin
# 	tools/gmssl.c
# 	tools/version.c
# 	tools/rand.c
# 	tools/sm2keygen.c
# 	tools/sm2sign.c
# 	tools/sm2verify.c
# 	tools/sm2encrypt.c
# 	tools/sm2decrypt.c
# 	tools/sm3.c
# 	tools/sm3hmac.c
# 	tools/sm4.c
# 	tools/zuc.c
# 	tools/sm9setup.c
# 	tools/sm9keygen.c
# 	tools/sm9sign.c
# 	tools/sm9verify.c
# 	tools/sm9encrypt.c
# 	tools/sm9decrypt.c
# 	tools/certgen.c
# 	tools/certparse.c
# 	tools/certverify.c
# 	tools/crlparse.c
# 	tools/pbkdf2.c
# 	tools/reqgen.c
# 	tools/reqparse.c
# 	tools/reqsign.c
# 	tools/tlcp_client.c
# 	tools/tlcp_server.c
# 	tools/tls12_client.c
# 	tools/tls12_server.c
# 	tools/tls13_client.c
# 	tools/tls13_server.c
# 	tools/sdfutil.c
# 	tools/skfutil.c
# )
# target_link_libraries (gmssl-bin LINK_PUBLIC gmssl)
# set_target_properties (gmssl-bin PROPERTIES RUNTIME_OUTPUT_NAME gmssl)



# tests
enable_testing()

# add_executable(sm3test test/sm3test.c)
# target_link_libraries (sm3test LINK_PUBLIC gmssl)

add_executable(sm4test test/sm4test.c)
target_link_libraries (sm4test LINK_PUBLIC gmssl)


enable_testing()
# add_test(NAME sm3		COMMAND sm3test)
add_test(NAME sm4		COMMAND sm4test)


