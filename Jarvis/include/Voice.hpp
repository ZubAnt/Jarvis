#pragma once

#ifndef VOICE_H
#define VOICE_H

#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "Command.hpp"
#include "SpeechKit.hpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  namespace VoiceConfigurations {
    using scriptName = std::string;
    using configurationFile = std::string;
    using resultSentenceKeySpeechKit = std::string;
    using settingsKeySpeechKit = std::string;
    using settingsKeysSpeechKitYandex = std::vector<settingsKeySpeechKit>;
    
    const scriptName scriptRecord = "../scripts/record.py";
    const configurationFile speechKitJson = "../conf/speechkit.json";
    const resultSentenceKeySpeechKit resultSentenceKey = "variant";
    const settingsKeysSpeechKitYandex keys = {"key", "uuid", "topic", "lang"};
  }
  
#define methods
#define params
  
  /*! \class Voice
   * \brief Описывает объект голос
   */
  class Voice final {
    /*!
     * \using std::string key
     * \brief Определяет тип для ключа
     */
    using Key = std::string;
    /*!
     * \using std::string data
     * \brief Определяет тип для значения
     */
    using Data = std::string;
    /*!
     * \using connection::Map map
     * \brief Определяет тип для отображения std::string -> std::string
     */
    using map = std::map<Key, Data>;
    /*!
     * \using std::string path
     * \brief Определяет тип для пути до конфигурационного файла
     */
    using path = std::string;
    /*!
     * \using std::string name
     * \brief Определяет тип для имени объекта, который имеет голос
     */
    using name = std::string;
    using sentence = std::string;
    
    public methods:
    /*!
     * \brief Конструктор
     * \param path Путь до конфигурационного файла
     * \param name Имя голоса
     */
    Voice(const name &name);
    /*!
     * \brief Деструктор
     */
    ~Voice() = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice(const Voice &copy) = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice(Voice &&copy) = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice & operator=(const Voice &copy) = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice & operator=(Voice &&copy) = default;
    /*!
     * \brief Конструктор копирования
     * \return bool Подтверждение - была ли сказана фраза
     */
    bool say();
    /*!
     * \brief Метод изменения фразы
     * \param sentence Предложение
     */
    void setSentence(const sentence &sentence);
    /*!
     * \brief Метод получения фразы
     * \return sentence Предложение
     */
    sentence getSentence() const;
    void record();
    sentence voiceRecognition();
    sentence recordAndGet();
    
    private methods:
    Voice() = delete;
    /*!
     * \brief Метод запуска воспроизведения голоса
     * \return bool Проверка - запустилось ли
     */
    bool execute();
    /*!
     * \brief Метод нахождения нужной команды
     * \param waves Сэмплы
     * \param sentence Фраза
     * \return bool Найдено ли
     */
    bool findCommand(const map &waves, const sentence &sentence);
    sentence sendVoiceToYandexSpeechKit(const path &path);
    map getSentenceMapFromYandexSpeechKit(const path &path);
    
    private params:
    name _name; /*!< Имя голоса*/
    map _waves; /*!< Необходимый сэмпл*/
    sentence _sentence; /*!< Фраза*/
  };
}

#endif // VOICE_H
