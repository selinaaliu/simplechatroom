// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: text.proto

#ifndef PROTOBUF_text_2eproto__INCLUDED
#define PROTOBUF_text_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
class Text;
class TextDefaultTypeInternal;
extern TextDefaultTypeInternal _Text_default_instance_;

namespace protobuf_text_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_text_2eproto

// ===================================================================

class Text : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Text) */ {
 public:
  Text();
  virtual ~Text();

  Text(const Text& from);

  inline Text& operator=(const Text& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Text(Text&& from) noexcept
    : Text() {
    *this = ::std::move(from);
  }

  inline Text& operator=(Text&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Text& default_instance();

  static inline const Text* internal_default_instance() {
    return reinterpret_cast<const Text*>(
               &_Text_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Text* other);
  friend void swap(Text& a, Text& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Text* New() const PROTOBUF_FINAL { return New(NULL); }

  Text* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Text& from);
  void MergeFrom(const Text& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Text* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string nickname = 1;
  bool has_nickname() const;
  void clear_nickname();
  static const int kNicknameFieldNumber = 1;
  const ::std::string& nickname() const;
  void set_nickname(const ::std::string& value);
  #if LANG_CXX11
  void set_nickname(::std::string&& value);
  #endif
  void set_nickname(const char* value);
  void set_nickname(const char* value, size_t size);
  ::std::string* mutable_nickname();
  ::std::string* release_nickname();
  void set_allocated_nickname(::std::string* nickname);

  // required string content = 3;
  bool has_content() const;
  void clear_content();
  static const int kContentFieldNumber = 3;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // required int32 chatroomId = 2;
  bool has_chatroomid() const;
  void clear_chatroomid();
  static const int kChatroomIdFieldNumber = 2;
  ::google::protobuf::int32 chatroomid() const;
  void set_chatroomid(::google::protobuf::int32 value);

  // required int32 msgId = 4;
  bool has_msgid() const;
  void clear_msgid();
  static const int kMsgIdFieldNumber = 4;
  ::google::protobuf::int32 msgid() const;
  void set_msgid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Text)
 private:
  void set_has_nickname();
  void clear_has_nickname();
  void set_has_chatroomid();
  void clear_has_chatroomid();
  void set_has_content();
  void clear_has_content();
  void set_has_msgid();
  void clear_has_msgid();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr nickname_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  ::google::protobuf::int32 chatroomid_;
  ::google::protobuf::int32 msgid_;
  friend struct protobuf_text_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Text

// required string nickname = 1;
inline bool Text::has_nickname() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Text::set_has_nickname() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Text::clear_has_nickname() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Text::clear_nickname() {
  nickname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_nickname();
}
inline const ::std::string& Text::nickname() const {
  // @@protoc_insertion_point(field_get:Text.nickname)
  return nickname_.GetNoArena();
}
inline void Text::set_nickname(const ::std::string& value) {
  set_has_nickname();
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Text.nickname)
}
#if LANG_CXX11
inline void Text::set_nickname(::std::string&& value) {
  set_has_nickname();
  nickname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Text.nickname)
}
#endif
inline void Text::set_nickname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_nickname();
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Text.nickname)
}
inline void Text::set_nickname(const char* value, size_t size) {
  set_has_nickname();
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Text.nickname)
}
inline ::std::string* Text::mutable_nickname() {
  set_has_nickname();
  // @@protoc_insertion_point(field_mutable:Text.nickname)
  return nickname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Text::release_nickname() {
  // @@protoc_insertion_point(field_release:Text.nickname)
  clear_has_nickname();
  return nickname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Text::set_allocated_nickname(::std::string* nickname) {
  if (nickname != NULL) {
    set_has_nickname();
  } else {
    clear_has_nickname();
  }
  nickname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nickname);
  // @@protoc_insertion_point(field_set_allocated:Text.nickname)
}

// required int32 chatroomId = 2;
inline bool Text::has_chatroomid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Text::set_has_chatroomid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Text::clear_has_chatroomid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Text::clear_chatroomid() {
  chatroomid_ = 0;
  clear_has_chatroomid();
}
inline ::google::protobuf::int32 Text::chatroomid() const {
  // @@protoc_insertion_point(field_get:Text.chatroomId)
  return chatroomid_;
}
inline void Text::set_chatroomid(::google::protobuf::int32 value) {
  set_has_chatroomid();
  chatroomid_ = value;
  // @@protoc_insertion_point(field_set:Text.chatroomId)
}

// required string content = 3;
inline bool Text::has_content() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Text::set_has_content() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Text::clear_has_content() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Text::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_content();
}
inline const ::std::string& Text::content() const {
  // @@protoc_insertion_point(field_get:Text.content)
  return content_.GetNoArena();
}
inline void Text::set_content(const ::std::string& value) {
  set_has_content();
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Text.content)
}
#if LANG_CXX11
inline void Text::set_content(::std::string&& value) {
  set_has_content();
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Text.content)
}
#endif
inline void Text::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_content();
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Text.content)
}
inline void Text::set_content(const char* value, size_t size) {
  set_has_content();
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Text.content)
}
inline ::std::string* Text::mutable_content() {
  set_has_content();
  // @@protoc_insertion_point(field_mutable:Text.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Text::release_content() {
  // @@protoc_insertion_point(field_release:Text.content)
  clear_has_content();
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Text::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    set_has_content();
  } else {
    clear_has_content();
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:Text.content)
}

// required int32 msgId = 4;
inline bool Text::has_msgid() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Text::set_has_msgid() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Text::clear_has_msgid() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Text::clear_msgid() {
  msgid_ = 0;
  clear_has_msgid();
}
inline ::google::protobuf::int32 Text::msgid() const {
  // @@protoc_insertion_point(field_get:Text.msgId)
  return msgid_;
}
inline void Text::set_msgid(::google::protobuf::int32 value) {
  set_has_msgid();
  msgid_ = value;
  // @@protoc_insertion_point(field_set:Text.msgId)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_text_2eproto__INCLUDED
