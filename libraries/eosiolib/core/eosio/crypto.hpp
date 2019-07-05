/**
 *  @file
 *  @copyright defined in eos/LICENSE
 */
#pragma once

#include "fixed_bytes.hpp"
#include "varint.hpp"
#include "serialize.hpp"

#include <array>

namespace eosio {
    namespace internal_use_do_not_use {
        extern "C" {
            __attribute__((eosio_wasm_import))
            int verify_rsa_sha256_sig(const void* message,   uint32_t message_len,
                                      const char* signature, uint32_t signature_len,
                                      const char* exponent,  uint32_t exponent_len,
                                      const char* modulus,   uint32_t modulus_len);
        }
    }


   /**
    *  @defgroup public_key Public Key Type
    *  @ingroup core
    *  @ingroup types
    *  @brief Specifies public key type
    */

   /**
    *  EOSIO Public Key
    *
    *  @ingroup public_key
    */
   struct public_key {
      /**
       *  Type of the public key, could be either K1 or R1
       */
      unsigned_int        type;

      /**
       *  Bytes of the public key
       */
      std::array<char,33> data;

      /// @cond OPERATORS

      friend bool operator == ( const public_key& a, const public_key& b ) {
        return std::tie(a.type,a.data) == std::tie(b.type,b.data);
      }
      friend bool operator != ( const public_key& a, const public_key& b ) {
        return std::tie(a.type,a.data) != std::tie(b.type,b.data);
      }

      /// @cond
   };

   /// @cond IMPLEMENTATIONS

   /**
    *  Serialize an eosio::public_key into a stream
    *
    *  @ingroup public_key
    *  @param ds - The stream to write
    *  @param pubkey - The value to serialize
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator<<(DataStream& ds, const eosio::public_key& pubkey) {
      ds << pubkey.type;
      ds.write( pubkey.data.data(), pubkey.data.size() );
      return ds;
   }

   /**
    *  Deserialize an eosio::public_key from a stream
    *
    *  @ingroup public_key
    *  @param ds - The stream to read
    *  @param pubkey - The destination for deserialized value
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator>>(DataStream& ds, eosio::public_key& pubkey) {
      ds >> pubkey.type;
      ds.read( pubkey.data.data(), pubkey.data.size() );
      return ds;
   }

   /// @endcond

   /**
    *  @defgroup signature Signature
    *  @ingroup core
    *  @ingroup types
    *  @brief Specifies signature type
    */

   /**
    *  EOSIO Signature
    *
    *  @ingroup signature
    */
   struct signature {

      /**
       *  Type of the signature, could be either K1 or R1
       */
      unsigned_int        type;

      /**
       *  Bytes of the signature
       */
      std::array<char,65> data;

      /// @cond OPERATORS

      friend bool operator == ( const signature& a, const signature& b ) {
        return std::tie(a.type,a.data) == std::tie(b.type,b.data);
      }
      friend bool operator != ( const signature& a, const signature& b ) {
        return std::tie(a.type,a.data) != std::tie(b.type,b.data);
      }

      /// @endcond
   };

   /// @cond IMPLEMENTATIONS

   /**
    *  Serialize an eosio::signature into a stream
    *
    *  @param ds - The stream to write
    *  @param sig - The value to serialize
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator<<(DataStream& ds, const eosio::signature& sig) {
      ds << sig.type;
      ds.write( sig.data.data(), sig.data.size() );
      return ds;
   }

   /**
    *  Deserialize an eosio::signature from a stream
    *
    *  @param ds - The stream to read
    *  @param sig - The destination for deserialized value
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator>>(DataStream& ds, eosio::signature& sig) {
      ds >> sig.type;
      ds.read( sig.data.data(), sig.data.size() );
      return ds;
   }

   /// @endcond

   /**
    *  @defgroup crypto Crypto
    *  @ingroup core
    *  @brief Defines API for calculating and checking hashes
    */

   /**
    *  @defgroup wax WAX
    *  @brief Defines custom WAX extension API
    *  @ingroup crypto
    */

   /**
    *  Tests if the SHA256 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    *  @note This method is optimized to a NO-OP when in fast evaluation mode.
    */
   void assert_sha256( const char* data, uint32_t length, const eosio::checksum256& hash );

   /**
    *  Tests if the SHA1 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    *  @note This method is optimized to a NO-OP when in fast evaluation mode.
    */
   void assert_sha1( const char* data, uint32_t length, const eosio::checksum160& hash );

   /**
    *  Tests if the SHA512 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    *  @note This method is optimized to a NO-OP when in fast evaluation mode.
    */
   void assert_sha512( const char* data, uint32_t length, const eosio::checksum512& hash );

   /**
    *  Tests if the RIPEMD160 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    */
   void assert_ripemd160( const char* data, uint32_t length, const eosio::checksum160& hash );

   /**
    *  Hashes `data` using SHA256.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return eosio::checksum256 - Computed digest
    */
   eosio::checksum256 sha256( const char* data, uint32_t length );

   /**
    *  Hashes `data` using SHA1.
    *
    *  @ingroup crypto
    *
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return eosio::checksum160 - Computed digest
    */
   eosio::checksum160 sha1( const char* data, uint32_t length );

   /**
    *  Hashes `data` using SHA512.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return eosio::checksum512 - Computed digest
    */
   eosio::checksum512 sha512( const char* data, uint32_t length );

   /**
    *  Hashes `data` using RIPEMD160.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return eosio::checksum160 - Computed digest
    */
   eosio::checksum160 ripemd160( const char* data, uint32_t length );

   /**
    *  Calculates the public key used for a given signature on a given digest.
    *
    *  @ingroup crypto
    *  @param digest - Digest of the message that was signed
    *  @param sig - Signature
    *  @return eosio::public_key - Recovered public key
    */
   eosio::public_key recover_key( const eosio::checksum256& digest, const eosio::signature& sig );

   /**
    *  Tests a given public key with the recovered public key from digest and signature.
    *
    *  @ingroup crypto
    *  @param digest - Digest of the message that was signed
    *  @param sig - Signature
    *  @param pubkey - Public key
    */
   void assert_recover_key( const eosio::checksum256& digest, const eosio::signature& sig, const eosio::public_key& pubkey );

    /**
     * Verifies an RSA signed message
     *
     * @warning WAX specific
     *
     * @ingroup wax
     * @param message - message buffer to verify
     * @param message_len - message buffer length
     * @param signature - signature as hex string
     * @param exponent - public key exponent as hex string
     * @param modulus - modulus as hex string (a leading zero is not allowed)
     *
     * @return false if validation has failed, true if everything is Ok
     *
     * @sa https://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
     *
     * @todo Check if this function must be removed (due to the old style message buffer)
     */
    inline bool verify_rsa_sha256_sig(const void* message,
                                      uint32_t message_len,
                                      std::string_view signature,
                                      std::string_view exponent,
                                      std::string_view modulus) {
        return internal_use_do_not_use::verify_rsa_sha256_sig(
            message, message_len,
            signature.data(), signature.size(),
            exponent.data(), exponent.size(),
            modulus.data(), modulus.size());
    }

    /**
     * Verifies an RSA signed message
     *
     * @warning WAX specific
     *
     * @ingroup wax
     * @param message - message to verify
     * @param signature - signature as hex string
     * @param exponent - public key exponent as hex string
     * @param modulus - modulus as hex string (a leading zero is not allowed)
     *
     * @return false if validation has failed, true if everything is Ok
     *
     * @sa https://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
     */
    inline bool verify_rsa_sha256_sig(std::string_view message,
                                      std::string_view signature,
                                      std::string_view exponent,
                                      std::string_view modulus) {
        return verify_rsa_sha256_sig(
            message.data(), message.size(), signature, exponent, modulus);
    }

    /**
     * Verifies an RSA signed message
     *
     * @warning WAX specific
     *
     * @ingroup wax
     * @param message - message to verify
     * @param signature - signature as hex string
     * @param exponent - public key exponent as hex string
     * @param modulus - modulus as hex string (a leading zero is not allowed)
     *
     * @return false if validation has failed, true if everything is Ok
     *
     * @sa https://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
     */
    template<typename T, typename A = std::allocator<T>>
    bool verify_rsa_sha256_sig(const std::vector<T, A>& message,
                               std::string_view signature,
                               std::string_view exponent,
                               std::string_view modulus) {
        return verify_rsa_sha256_sig(
            message.data(), message.size()*sizeof(T), signature, exponent, modulus);
    }

    /**
     * Verifies an RSA signed message
     *
     * @warning WAX specific
     *
     * @ingroup wax
     * @param message - message to verify
     * @param signature - signature as hex string
     * @param exponent - public key exponent as hex string
     * @param modulus - modulus as hex string (a leading zero is not allowed)
     *
     * @return false if validation has failed, true if everything is Ok
     *
     * @sa https://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
     */
    template<typename T, std::size_t N>
    bool verify_rsa_sha256_sig(const std::array<T, N>& message,
                               std::string_view signature,
                               std::string_view exponent,
                               std::string_view modulus) {
        return verify_rsa_sha256_sig(
            message.data(), message.size()*sizeof(T), signature, exponent, modulus);
    }

} // namespace eosio
