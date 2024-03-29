/*
 * Copyright (c) 2020, Rauli Laine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include <memory>
#include <vector>

#include <plorth/parser/position.hpp>

namespace plorth::parser::ast
{
  /**
   * Abstract base class for various elements that might appear in source code
   * of Plorth program.
   */
  class token
  {
  public:
    /**
     * Enumeration of different token types.
     */
    enum class type
    {
      /** Array literal. */
      array = '[',
      /** Object literal. */
      object = '{',
      /** Quote literal. */
      quote = '(',
      /** String literal. */
      string = '"',
      /** Symbol. */
      symbol = 's',
      /** Word definition. */
      word = ':'
    };

    /**
     * Base constructor for an token.
     *
     * \param position Position in source code where the token was found from.
     */
    explicit token(const struct position& position)
      : m_position(position) {}

    virtual ~token() {}

    /**
     * Returns the position in source code where the token was found from.
     */
    inline const struct position& position() const
    {
      return m_position;
    }

    /**
     * Returns type of the token.
     */
    virtual enum type type() const = 0;

    token(const token&) = delete;
    token(token&&) = delete;
    void operator=(const token&) = delete;
    void operator=(token&&) = delete;

  private:
    /** Position in source code where the token was found from. */
    const struct position m_position;
  };

  /**
   * Representation of array literal.
   */
  class array : public token
  {
  public:
    using container_type = std::vector<std::shared_ptr<token>>;

    explicit array(
      const struct position& position,
      const container_type& elements
    )
      : token(position)
      , m_elements(elements) {}

    inline enum type type() const
    {
      return type::array;
    }

    /**
     * Returns elements of the array.
     */
    inline const container_type& elements() const
    {
      return m_elements;
    }

  private:
    /** Elements of the array. */
    const container_type m_elements;
  };

  /**
   * Representation of object literal.
   */
  class object : public token
  {
  public:
    using key_type = std::u32string;
    using mapped_type = std::shared_ptr<token>;
    using value_type = std::pair<key_type, mapped_type>;
    using container_type = std::vector<value_type>;

    explicit object(
      const struct position& position,
      const container_type& properties
    )
      : token(position)
      , m_properties(properties) {}

    inline enum type type() const
    {
      return type::object;
    }

    /**
     * Returns properties of the object.
     */
    inline const container_type& properties() const
    {
      return m_properties;
    }

  private:
    /** Properties of the object. */
    const container_type m_properties;
  };

  /**
   * Representation of quote literal.
   */
  class quote : public token
  {
  public:
    using container_type = std::vector<std::shared_ptr<token>>;

    explicit quote(
      const struct position& position,
      const container_type& children
    )
      : token(position)
      , m_children(children) {}

    inline enum type type() const
    {
      return type::quote;
    }

    /**
     * Returns child tokens of the quote.
     */
    inline const container_type& children() const
    {
      return m_children;
    }

  private:
    /** Child tokens of the quote. */
    const container_type m_children;
  };

  /**
   * Representation of string literal.
   */
  class string : public token
  {
  public:
    using value_type = std::u32string;

    explicit string(const struct position& position, const value_type& value)
      : token(position)
      , m_value(value) {}

    inline enum type type() const
    {
      return type::string;
    }

    /**
     * Returns text contents of the string literal.
     */
    inline const value_type& value() const
    {
      return m_value;
    }

  private:
    /** Text contents of the string literal. */
    const value_type m_value;
  };

  /**
   * Representation of symbol.
   */
  class symbol : public token
  {
  public:
    using id_type = std::u32string;

    explicit symbol(const struct position& position, const id_type& id)
      : token(position)
      , m_id(id) {}

    inline enum type type() const
    {
      return type::symbol;
    }

    /**
     * Returns identifier of the symbol.
     */
    inline const id_type& id() const
    {
      return m_id;
    }

  private:
    /** Identifier of the symbol. */
    const id_type m_id;
  };

  /**
   * Representation of word definition.
   */
  class word : public token
  {
  public:
    using symbol_type = std::shared_ptr<class symbol>;

    explicit word(
      const struct position& position,
      const symbol_type& symbol
    )
      : token(position)
      , m_symbol(symbol) {}

    inline enum type type() const
    {
      return type::word;
    }

    /**
     * Returns identifier of the word.
     */
    inline const symbol_type& symbol() const
    {
      return m_symbol;
    }

  private:
    /** Identifier of the word. */
    const symbol_type m_symbol;
  };
}
