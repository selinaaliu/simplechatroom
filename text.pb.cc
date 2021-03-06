// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: text.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "text.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
class TextDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<Text>
     _instance;
} _Text_default_instance_;

namespace protobuf_text_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Text, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Text, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Text, nickname_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Text, chatroomid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Text, content_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Text, msgid_),
  0,
  2,
  1,
  3,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(Text)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_Text_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "text.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _Text_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_Text_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\ntext.proto\"L\n\004Text\022\020\n\010nickname\030\001 \002(\t\022\022"
      "\n\nchatroomId\030\002 \002(\005\022\017\n\007content\030\003 \002(\t\022\r\n\005m"
      "sgId\030\004 \002(\005"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 90);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "text.proto", &protobuf_RegisterTypes);
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_text_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Text::kNicknameFieldNumber;
const int Text::kChatroomIdFieldNumber;
const int Text::kContentFieldNumber;
const int Text::kMsgIdFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Text::Text()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_text_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Text)
}
Text::Text(const Text& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  nickname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_nickname()) {
    nickname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nickname_);
  }
  content_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_content()) {
    content_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.content_);
  }
  ::memcpy(&chatroomid_, &from.chatroomid_,
    static_cast<size_t>(reinterpret_cast<char*>(&msgid_) -
    reinterpret_cast<char*>(&chatroomid_)) + sizeof(msgid_));
  // @@protoc_insertion_point(copy_constructor:Text)
}

void Text::SharedCtor() {
  _cached_size_ = 0;
  nickname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  content_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&chatroomid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&msgid_) -
      reinterpret_cast<char*>(&chatroomid_)) + sizeof(msgid_));
}

Text::~Text() {
  // @@protoc_insertion_point(destructor:Text)
  SharedDtor();
}

void Text::SharedDtor() {
  nickname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  content_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Text::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Text::descriptor() {
  protobuf_text_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_text_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Text& Text::default_instance() {
  protobuf_text_2eproto::InitDefaults();
  return *internal_default_instance();
}

Text* Text::New(::google::protobuf::Arena* arena) const {
  Text* n = new Text;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Text::Clear() {
// @@protoc_insertion_point(message_clear_start:Text)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!nickname_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*nickname_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!content_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*content_.UnsafeRawStringPointer())->clear();
    }
  }
  if (cached_has_bits & 12u) {
    ::memset(&chatroomid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&msgid_) -
        reinterpret_cast<char*>(&chatroomid_)) + sizeof(msgid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Text::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Text)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string nickname = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nickname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->nickname().data(), static_cast<int>(this->nickname().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Text.nickname");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 chatroomId = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_chatroomid();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &chatroomid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required string content = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_content()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->content().data(), static_cast<int>(this->content().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Text.content");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 msgId = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_msgid();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &msgid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Text)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Text)
  return false;
#undef DO_
}

void Text::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Text)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string nickname = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nickname().data(), static_cast<int>(this->nickname().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Text.nickname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->nickname(), output);
  }

  // required int32 chatroomId = 2;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->chatroomid(), output);
  }

  // required string content = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->content().data(), static_cast<int>(this->content().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Text.content");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->content(), output);
  }

  // required int32 msgId = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->msgid(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Text)
}

::google::protobuf::uint8* Text::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Text)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string nickname = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nickname().data(), static_cast<int>(this->nickname().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Text.nickname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->nickname(), target);
  }

  // required int32 chatroomId = 2;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->chatroomid(), target);
  }

  // required string content = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->content().data(), static_cast<int>(this->content().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Text.content");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->content(), target);
  }

  // required int32 msgId = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->msgid(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Text)
  return target;
}

size_t Text::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Text)
  size_t total_size = 0;

  if (has_nickname()) {
    // required string nickname = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->nickname());
  }

  if (has_content()) {
    // required string content = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->content());
  }

  if (has_chatroomid()) {
    // required int32 chatroomId = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->chatroomid());
  }

  if (has_msgid()) {
    // required int32 msgId = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgid());
  }

  return total_size;
}
size_t Text::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Text)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required string nickname = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->nickname());

    // required string content = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->content());

    // required int32 chatroomId = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->chatroomid());

    // required int32 msgId = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->msgid());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Text::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Text)
  GOOGLE_DCHECK_NE(&from, this);
  const Text* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Text>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Text)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Text)
    MergeFrom(*source);
  }
}

void Text::MergeFrom(const Text& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Text)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_nickname();
      nickname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nickname_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_content();
      content_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.content_);
    }
    if (cached_has_bits & 0x00000004u) {
      chatroomid_ = from.chatroomid_;
    }
    if (cached_has_bits & 0x00000008u) {
      msgid_ = from.msgid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Text::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Text)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Text::CopyFrom(const Text& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Text)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Text::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  return true;
}

void Text::Swap(Text* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Text::InternalSwap(Text* other) {
  using std::swap;
  nickname_.Swap(&other->nickname_);
  content_.Swap(&other->content_);
  swap(chatroomid_, other->chatroomid_);
  swap(msgid_, other->msgid_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Text::GetMetadata() const {
  protobuf_text_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_text_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Text

// required string nickname = 1;
bool Text::has_nickname() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void Text::set_has_nickname() {
  _has_bits_[0] |= 0x00000001u;
}
void Text::clear_has_nickname() {
  _has_bits_[0] &= ~0x00000001u;
}
void Text::clear_nickname() {
  nickname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_nickname();
}
const ::std::string& Text::nickname() const {
  // @@protoc_insertion_point(field_get:Text.nickname)
  return nickname_.GetNoArena();
}
void Text::set_nickname(const ::std::string& value) {
  set_has_nickname();
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Text.nickname)
}
#if LANG_CXX11
void Text::set_nickname(::std::string&& value) {
  set_has_nickname();
  nickname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Text.nickname)
}
#endif
void Text::set_nickname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_nickname();
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Text.nickname)
}
void Text::set_nickname(const char* value, size_t size) {
  set_has_nickname();
  nickname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Text.nickname)
}
::std::string* Text::mutable_nickname() {
  set_has_nickname();
  // @@protoc_insertion_point(field_mutable:Text.nickname)
  return nickname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Text::release_nickname() {
  // @@protoc_insertion_point(field_release:Text.nickname)
  clear_has_nickname();
  return nickname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Text::set_allocated_nickname(::std::string* nickname) {
  if (nickname != NULL) {
    set_has_nickname();
  } else {
    clear_has_nickname();
  }
  nickname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nickname);
  // @@protoc_insertion_point(field_set_allocated:Text.nickname)
}

// required int32 chatroomId = 2;
bool Text::has_chatroomid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void Text::set_has_chatroomid() {
  _has_bits_[0] |= 0x00000004u;
}
void Text::clear_has_chatroomid() {
  _has_bits_[0] &= ~0x00000004u;
}
void Text::clear_chatroomid() {
  chatroomid_ = 0;
  clear_has_chatroomid();
}
::google::protobuf::int32 Text::chatroomid() const {
  // @@protoc_insertion_point(field_get:Text.chatroomId)
  return chatroomid_;
}
void Text::set_chatroomid(::google::protobuf::int32 value) {
  set_has_chatroomid();
  chatroomid_ = value;
  // @@protoc_insertion_point(field_set:Text.chatroomId)
}

// required string content = 3;
bool Text::has_content() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void Text::set_has_content() {
  _has_bits_[0] |= 0x00000002u;
}
void Text::clear_has_content() {
  _has_bits_[0] &= ~0x00000002u;
}
void Text::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_content();
}
const ::std::string& Text::content() const {
  // @@protoc_insertion_point(field_get:Text.content)
  return content_.GetNoArena();
}
void Text::set_content(const ::std::string& value) {
  set_has_content();
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Text.content)
}
#if LANG_CXX11
void Text::set_content(::std::string&& value) {
  set_has_content();
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Text.content)
}
#endif
void Text::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_content();
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Text.content)
}
void Text::set_content(const char* value, size_t size) {
  set_has_content();
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Text.content)
}
::std::string* Text::mutable_content() {
  set_has_content();
  // @@protoc_insertion_point(field_mutable:Text.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Text::release_content() {
  // @@protoc_insertion_point(field_release:Text.content)
  clear_has_content();
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Text::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    set_has_content();
  } else {
    clear_has_content();
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:Text.content)
}

// required int32 msgId = 4;
bool Text::has_msgid() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void Text::set_has_msgid() {
  _has_bits_[0] |= 0x00000008u;
}
void Text::clear_has_msgid() {
  _has_bits_[0] &= ~0x00000008u;
}
void Text::clear_msgid() {
  msgid_ = 0;
  clear_has_msgid();
}
::google::protobuf::int32 Text::msgid() const {
  // @@protoc_insertion_point(field_get:Text.msgId)
  return msgid_;
}
void Text::set_msgid(::google::protobuf::int32 value) {
  set_has_msgid();
  msgid_ = value;
  // @@protoc_insertion_point(field_set:Text.msgId)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
